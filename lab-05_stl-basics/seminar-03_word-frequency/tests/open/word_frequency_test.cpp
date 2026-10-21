#include <map>
#include <string>

#include <gtest/gtest.h>

#include "word_frequency.hpp"

using Frequency = std::map<std::string, int>;

TEST(WordFrequencyTest, Example)
{
    EXPECT_EQ(buildWordFrequency({"The cat, the dog.", "The end!"}),
              (Frequency{{"The", 2}, {"cat", 1}, {"dog", 1}, {"end", 1}, {"the", 1}}));
}

TEST(WordFrequencyTest, PunctuationInsideWord)
{
    EXPECT_EQ(buildWordFrequency({"don't stop"}), (Frequency{{"dont", 1}, {"stop", 1}}));
}
