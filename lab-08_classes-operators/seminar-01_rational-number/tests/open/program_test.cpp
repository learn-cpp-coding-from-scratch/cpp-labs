#include <sstream>
#include <string>

#include <gtest/gtest.h>

#include "program.hpp"

namespace {

std::string runProgram(const std::string& input)
{
    std::istringstream in{input};
    std::ostringstream out;
    Program program;
    program.run(in, out);
    return out.str();
}

bool contains(const std::string& text, const std::string& part)
{
    return text.find(part) != std::string::npos;
}

} // namespace

TEST(ProgramTest, ArithmeticAndComparisons)
{
    const std::string output = runProgram("1 2\n1 3\n");
    EXPECT_TRUE(contains(output, "a = 1/2\n"));
    EXPECT_TRUE(contains(output, "b = 1/3\n"));
    EXPECT_TRUE(contains(output, "a + b = 5/6\n"));
    EXPECT_TRUE(contains(output, "a - b = 1/6\n"));
    EXPECT_TRUE(contains(output, "a * b = 1/6\n"));
    EXPECT_TRUE(contains(output, "a / b = 3/2\n"));
    EXPECT_TRUE(contains(output, "a == b: false\n"));
    EXPECT_TRUE(contains(output, "a < b: false\n"));
    EXPECT_TRUE(contains(output, "a >= b: true\n"));
}

TEST(ProgramTest, ZeroDenominatorAsksAgain)
{
    const std::string output = runProgram("1 0\n1 2\n1 3\n");
    EXPECT_TRUE(contains(output, "Error: "));
    EXPECT_TRUE(contains(output, "a = 1/2\n"));
}

TEST(ProgramTest, DivisionByZero)
{
    const std::string output = runProgram("1 2\n0 1\n");
    EXPECT_TRUE(contains(output, "a / b = Error: "));
    EXPECT_TRUE(contains(output, "a > b: true\n"));
}

TEST(ProgramTest, InputError)
{
    const std::string output = runProgram("abc\n");
    EXPECT_TRUE(contains(output, "Error: input error\n"));
    EXPECT_FALSE(contains(output, "a = "));
}
