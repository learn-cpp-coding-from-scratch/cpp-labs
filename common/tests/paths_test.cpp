#include <filesystem>

#include <gtest/gtest.h>

#include <cpplabs/paths.hpp>

TEST(ExecutableDirectoryTest, IsExistingAbsoluteDirectory)
{
    const std::filesystem::path directory = cpplabs::executableDirectory();
    EXPECT_TRUE(directory.is_absolute());
    EXPECT_TRUE(std::filesystem::is_directory(directory));
}

TEST(ExecutableDirectoryTest, DoesNotDependOnCurrentPath)
{
    const std::filesystem::path before = cpplabs::executableDirectory();
    const std::filesystem::path saved = std::filesystem::current_path();
    std::filesystem::current_path(std::filesystem::temp_directory_path());
    const std::filesystem::path after = cpplabs::executableDirectory();
    std::filesystem::current_path(saved);
    EXPECT_EQ(before, after);
}

TEST(DataDirectoryTest, IsDataNextToExecutable)
{
    EXPECT_EQ(cpplabs::dataDirectory(), cpplabs::executableDirectory() / "data");
}
