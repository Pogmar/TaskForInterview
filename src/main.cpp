//Create the application that will analyze and show statistics of specified directory that will handle recursive directories. (OK)
//It should print number of files and total number of lines (might as well count non - empty and empty lines). (OK)
//Provide unit tests for solutions. (OK)
//- Application should use multithreading (keep in mind system limitations, you might need to control number of concurrent calls, e.g., use thread pool). (OK)
//- Use std::filesystem (OK)
//- Use GTest for Unit Tests (OK)
//- As a bonus, you could also count words and letters and provide performance benchmarks(e.g., measure the impact of using the different number of threads). (NOK)

#include "analyzer.h"
#include <exception>

int main()
{
	analyzer::AsyncThreadPool t(std::thread::hardware_concurrency());
	fs::path root = "/mnt/d/_programowanie/BCF_task/root";

    try
	{
        analyzer::DirectoryStats rootResult = analyzer::analyze(root, t);
        analyzer::printResult(rootResult);
    }
    catch (std::exception e)
	{
        std::cout << e.what();
    }

	return 0;
}