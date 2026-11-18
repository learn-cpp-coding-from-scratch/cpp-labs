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

TEST(ProgramTest, Arithmetic)
{
    const std::string output = runProgram("1\n1 2\n3 -1\n0\n");
    EXPECT_TRUE(contains(output, "z1 = (1, 2)\n"));
    EXPECT_TRUE(contains(output, "z1 + z2 = (4, 1)\n"));
    EXPECT_TRUE(contains(output, "z1 * z2 = (5, 5)\n"));
    EXPECT_TRUE(contains(output, "z1 / z2 = (0.1, 0.7)\n"));
    EXPECT_TRUE(contains(output, "conj(z1) = (1, -2)\n"));
    EXPECT_TRUE(contains(output, "z1 == z2: false\n"));
}

TEST(ProgramTest, DivisionByZero)
{
    const std::string output = runProgram("1\n1 2\n0 0\n0\n");
    EXPECT_TRUE(contains(output, "z1 / z2 = Error: "));
    EXPECT_TRUE(contains(output, "|z2| = 0\n"));
}

TEST(ProgramTest, Mandelbrot)
{
    const std::string output = runProgram("2\n-2.2 0.8 -1.2 1.2\n50\n0\n");
    EXPECT_TRUE(contains(output, "     " + std::string(53, '@')));
}

TEST(ProgramTest, InvalidAreaThenMenuAgain)
{
    const std::string output = runProgram("2\n1 -1 -1 1\n50\n7\n0\n");
    EXPECT_TRUE(contains(output, "Error: "));
    EXPECT_TRUE(contains(output, "Unknown choice: 7\n"));
}
