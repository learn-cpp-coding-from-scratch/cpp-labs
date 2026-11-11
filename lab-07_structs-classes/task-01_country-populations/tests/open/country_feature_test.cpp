#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "country_feature.hpp"

TEST(CountryFeatureTest, ParseIncomeGroup)
{
    EXPECT_EQ(parseIncomeGroup("High income"), IncomeGroup::HIGH);
    EXPECT_EQ(parseIncomeGroup("Upper middle income"), IncomeGroup::UPPER_MIDDLE);
    EXPECT_EQ(parseIncomeGroup("Lower middle income"), IncomeGroup::LOWER_MIDDLE);
    EXPECT_EQ(parseIncomeGroup("Low income"), IncomeGroup::LOW);
}

TEST(CountryFeatureTest, IncomeGroupToString)
{
    EXPECT_EQ(toString(IncomeGroup::HIGH), "High income");
    EXPECT_EQ(toString(IncomeGroup::LOW), "Low income");
}

TEST(CountryFeatureTest, ParseCountryFeature)
{
    const CountryFeature feature = parseCountryFeature("AFG;South Asia;Low income;Afghanistan");
    EXPECT_EQ(feature.getCode(), "AFG");
    EXPECT_EQ(feature.getRegion(), "South Asia");
    EXPECT_EQ(feature.getIncomeGroup(), IncomeGroup::LOW);
}

TEST(CountryFeatureTest, OutputOperator)
{
    const CountryFeature feature("AFG", "South Asia", IncomeGroup::LOW);
    std::ostringstream out;
    out << feature;
    EXPECT_EQ(out.str(), "AFG: South Asia, Low income");
}

TEST(CountryFeatureTest, ReadCountryFeatureFromFile)
{
    const auto* test = ::testing::UnitTest::GetInstance()->current_test_info();
    const std::filesystem::path path = std::filesystem::temp_directory_path() /
                                       (std::string("country_populations_") + test->test_suite_name() + "_" +
                                        test->name() + ".csv");
    std::ofstream(path) << "Country Code;Region;IncomeGroup;Country Name\n"
                           "AFG;South Asia;Low income;Afghanistan\n"
                           "ALB;Europe & Central Asia;Upper middle income;Albania\n";
    const std::vector<CountryFeature> features = readCountryFeatureFromFile(path);
    ASSERT_EQ(features.size(), 2U);
    EXPECT_EQ(features[0].getCode(), "AFG");
    EXPECT_EQ(features[1].getRegion(), "Europe & Central Asia");
    EXPECT_EQ(features[1].getIncomeGroup(), IncomeGroup::UPPER_MIDDLE);
}
