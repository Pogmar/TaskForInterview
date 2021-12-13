#include "gtest/gtest.h"
#include "analyzer.h"

TEST(AnalyzeTest, ExpectedOutputTest)
{
    analyzer::AsyncThreadPool t(std::thread::hardware_concurrency());
    fs::path root = "/mnt/d/_programowanie/BCF_task/root";
    analyzer::DirectoryStats rootResult = analyzer::analyze(root, t);

    EXPECT_EQ (rootResult.m_numberOfFiles,  12);
    EXPECT_EQ (rootResult.m_numberOfLines,  5);
}

TEST(CountLinesTest, ExpectedOutputTest)
{
    EXPECT_EQ (analyzer::countLines("/mnt/d/_programowanie/BCF_task/root/child1/1f1.txt"), 1);
}

TEST(AnalyzeTest, WrongDirectoryTest)
{
    analyzer::AsyncThreadPool t(std::thread::hardware_concurrency());
    fs::path root = "/mnt/d/_programowanie/BCF_task/rootx";
    EXPECT_ANY_THROW(analyze(root, t));
}