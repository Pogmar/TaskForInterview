#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

#include <thread>
#include <future>
#include <mutex>
#include <atomic>

#include <utility>
#include <tuple>
#include <vector>
#include <map>

#include <functional>

namespace fs = std::filesystem;

namespace analyzer
{
	struct DirectoryStats
	{
		DirectoryStats()
		: m_numberOfLines(0)
		, m_numberOfFiles(0)
		{}

		int m_numberOfLines;
		int m_numberOfFiles;

		DirectoryStats& operator+(const DirectoryStats& rhs)
		{
			m_numberOfFiles = m_numberOfFiles + rhs.m_numberOfFiles;
			m_numberOfLines = m_numberOfLines + rhs.m_numberOfLines;
			return *this;
		}

		DirectoryStats& operator+=(const DirectoryStats& rhs)
		{
			m_numberOfFiles += rhs.m_numberOfFiles;
			m_numberOfLines += rhs.m_numberOfLines;
			return *this;
		}
	};

	int countLines(const fs::path& path)
	{
		int lines = 0;
		std::string line;
		std::fstream myfile;
		myfile.open(path.string().c_str(), std::ios::in);

		while (std::getline(myfile, line))
		{
			++lines;
		}	

		myfile.close();

		return lines;
	}

	class AsyncThreadPool
	{
	private:
		struct FutureLaunchingPolicy
		{
			FutureLaunchingPolicy(const std::shared_future<DirectoryStats>& f, std::launch p)
			: future(f)
			, policy(p)
			{}
			std::shared_future<DirectoryStats> future;
			std::launch policy;
		};

	public:
		AsyncThreadPool(uint32_t maxThreadCount)
		: maxThreadCount(maxThreadCount)
		, threadCount(0)
		{
		}

		template<typename F, typename v1, typename v2>
		void launch(const F& task, const v1& path, const v2& pool)
		//void launch(const std::function<DirectoryStats(const fs::path&, AsyncThreadPool&)>& task, const fs::path& path, const AsyncThreadPool& pool)
		{
			std::lock_guard<std::mutex> lock(taskMutex);
			if (threadCount < maxThreadCount)
			{
				std::cout << "Launching new thread...\n";
				++threadCount;
				std::future<DirectoryStats> fut = std::async(std::launch::async, task, path, pool);
				std::shared_future<DirectoryStats> share = fut.share();
				tasks.emplace(std::piecewise_construct,
					std::forward_as_tuple(path),
					std::forward_as_tuple(share, std::launch::async));
			}
			else
			{
				std::cout << "Launching deferred...\n";
				std::future<DirectoryStats> fut = std::async(std::launch::deferred, task, path, pool);
				std::shared_future<DirectoryStats> share = fut.share();
				tasks.emplace(std::piecewise_construct,
					std::forward_as_tuple(path),
					std::forward_as_tuple(share, std::launch::deferred));
			}
			return;
		}

		DirectoryStats getFutureValue(fs::path path)
		{
			FutureLaunchingPolicy futurePolicy = tasks.at(path);
			futurePolicy.future.wait();
			taskMutex.lock();
			if (futurePolicy.policy == std::launch::async)
			{
				std::cout << "Back thread to the pool...\n";
				--threadCount;
			}
			tasks.erase(path);
			taskMutex.unlock();
			return futurePolicy.future.get();
		}

	private:
		std::atomic<int> threadCount;
		int maxThreadCount;
		std::map<fs::path, FutureLaunchingPolicy> tasks;
		std::mutex taskMutex;
	};

	DirectoryStats analyze(const fs::path& directory, AsyncThreadPool& pool)
	{
		if (!fs::exists(directory))
		{
			throw "Folder not exists! Logic error";
		}

		std::vector<fs::path> futureDirectoryStats;
		DirectoryStats result;

		for (const auto& dir_entry : fs::directory_iterator(directory))
		{
			if (fs::is_directory(dir_entry))
			{
				futureDirectoryStats.push_back(dir_entry.path());
				pool.launch(&analyze, dir_entry.path(), std::ref(pool)); 
			}
			else if (fs::is_regular_file(dir_entry))
			{
				result.m_numberOfLines += countLines(dir_entry.path());
				result.m_numberOfFiles += 1;
			}
			else
			{
				result.m_numberOfFiles += 1;
			}
		}

		for (auto& el : futureDirectoryStats)
		{
			result += pool.getFutureValue(el);
		}
		
		return result;
	};

	void printResult(DirectoryStats result)
	{
		std::cout << "Number of lines in given directory: " << result.m_numberOfLines << std::endl;
		std::cout << "Number of files in given directory: " << result.m_numberOfFiles << std::endl;
		return;
	}
}