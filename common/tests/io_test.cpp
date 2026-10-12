#include <array>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <cpplabs/io.hpp>

TEST(PrintCollectionTest, DefaultDelimiter)
{
    std::ostringstream out;
    cpplabs::printCollection(std::vector<int>{1, 2, 3}, ", ", out);
    EXPECT_EQ(out.str(), "1, 2, 3\n");
}

TEST(PrintCollectionTest, CustomDelimiterAndType)
{
    std::ostringstream out;
    cpplabs::printCollection(std::vector<unsigned int>{6, 28, 496}, " ", out);
    cpplabs::printCollection(std::vector<std::string>{"a", "b"}, " | ", out);
    EXPECT_EQ(out.str(), "6 28 496\na | b\n");
}

TEST(PrintCollectionTest, Doubles)
{
    std::ostringstream out;
    cpplabs::printCollection(std::vector<double>{0.5, 2.25}, "; ", out);
    EXPECT_EQ(out.str(), "0.5; 2.25\n");
}

TEST(PrintCollectionTest, EmptyAndSingle)
{
    std::ostringstream out;
    cpplabs::printCollection(std::vector<int>{}, ", ", out);
    cpplabs::printCollection(std::vector<int>{7}, ", ", out);
    EXPECT_EQ(out.str(), "\n7\n");
}

TEST(PrintCollectionTest, OtherContainers)
{
    std::ostringstream out;
    cpplabs::printCollection(std::array<int, 3>{4, 5, 6}, " ", out);
    cpplabs::printCollection(std::set<int>{3, 1, 2}, ", ", out); // set хранит элементы по возрастанию
    const int numbers[] = {8, 9};
    cpplabs::printCollection(numbers, "-", out);
    EXPECT_EQ(out.str(), "4 5 6\n1, 2, 3\n8-9\n");
}

TEST(ReadNumberTest, ValidNumber)
{
    std::istringstream in("42\n");
    std::ostringstream out;
    EXPECT_EQ(cpplabs::readNumber("n = ", in, out), 42);
    EXPECT_EQ(out.str(), "n = ");
}

TEST(ReadNumberTest, SpacesAndSign)
{
    std::istringstream in("  -5 \n");
    std::ostringstream out;
    EXPECT_EQ(cpplabs::readNumber("n = ", in, out), -5);
}

TEST(ReadNumberTest, SeveralNumbersInOneLine)
{
    std::istringstream in("3 4\n");
    std::ostringstream out;
    EXPECT_EQ(cpplabs::readNumber("a = ", in, out), 3);
    EXPECT_EQ(cpplabs::readNumber("b = ", in, out), 4);
    EXPECT_EQ(out.str(), "a = b = ");
}
