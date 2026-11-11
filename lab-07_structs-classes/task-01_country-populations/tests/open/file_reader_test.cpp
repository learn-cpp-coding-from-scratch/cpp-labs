#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "file_reader.hpp"

namespace {

// Временный файл с содержимым content; имя — по имени теста, чтобы тесты, запущенные
// одновременно, не мешали друг другу
std::filesystem::path writeTemporaryFile(const std::string& content)
{
    const auto* test = ::testing::UnitTest::GetInstance()->current_test_info();
    const std::filesystem::path path = std::filesystem::temp_directory_path() /
                                       (std::string("country_populations_") + test->test_suite_name() + "_" +
                                        test->name() + ".csv");
    std::ofstream(path, std::ios::binary) << content;
    return path;
}

} // namespace

TEST(FileReaderTest, ReadLines)
{
    const auto path = writeTemporaryFile("a;b\n\nc\n");
    EXPECT_EQ(FileReader::read(path), (std::vector<std::string>{"a;b", "", "c"}));
}

TEST(FileReaderTest, ReadWindowsLineEndings)
{
    const auto path = writeTemporaryFile("a;b\r\nc\r\n");
    EXPECT_EQ(FileReader::read(path), (std::vector<std::string>{"a;b", "c"}));
}

TEST(FileReaderTest, ReadMissingFile)
{
    EXPECT_THROW(FileReader::read("no-such-directory/no-such-file.csv"), std::runtime_error);
}

TEST(FileReaderTest, Split)
{
    EXPECT_EQ(split("Afghanistan;AFG;8996973", ';'), (std::vector<std::string>{"Afghanistan", "AFG", "8996973"}));
}

TEST(FileReaderTest, SplitEmptyFields)
{
    EXPECT_EQ(split("a;;b;", ';'), (std::vector<std::string>{"a", "", "b", ""}));
}
