#include <gtest/gtest.h>

#include "complex_number.hpp"

TEST(ComplexEqualityCpp17Test, LanguageStandardIsCpp17)
{
    // Задача собирается с -std=c++17: в C++20 операнды == переставлялись бы автоматически.
    // MSVC без /Zc:__cplusplus сообщает в __cplusplus 199711L, настоящий стандарт — в _MSVC_LANG
#ifdef _MSVC_LANG
    EXPECT_EQ(_MSVC_LANG, 201703L);
#else
    EXPECT_EQ(__cplusplus, 201703L);
#endif
}

TEST(ComplexEqualityCpp17Test, TwoComplexNumbers)
{
    EXPECT_TRUE(ComplexNumber(1.0, 2.0) == ComplexNumber(1.0, 2.0));
    EXPECT_FALSE(ComplexNumber(1.0, 2.0) == ComplexNumber(1.0, -2.0));
    EXPECT_TRUE(ComplexNumber(1.0, 2.0) != ComplexNumber(2.0, 1.0));
    EXPECT_FALSE(ComplexNumber(1.0, 2.0) != ComplexNumber(1.0, 2.0));
}

TEST(ComplexEqualityCpp17Test, DoubleOnEitherSide)
{
    const ComplexNumber z{1.0, 0.0};
    EXPECT_TRUE(z == 1.0);
    EXPECT_TRUE(1.0 == z);
    EXPECT_FALSE(z != 1.0);
    EXPECT_FALSE(1.0 != z);
}
