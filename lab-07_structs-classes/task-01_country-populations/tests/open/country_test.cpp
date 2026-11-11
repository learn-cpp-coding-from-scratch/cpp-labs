#include <map>
#include <sstream>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "country.hpp"

TEST(CountryTest, ToString)
{
    const Country country{"Afghanistan", "AFG", {{1960, 8996973}, {1961, 9169410}}};
    EXPECT_EQ(country.toString(), "Afghanistan (AFG): 8996973[1960], 9169410[1961]");
}

TEST(CountryTest, OutputOperator)
{
    const Country country{"Afghanistan", "AFG", {{1960, 8996973}, {1961, 9169410}}};
    std::ostringstream out;
    out << country;
    EXPECT_EQ(out.str(), "Afghanistan (AFG): 8996973[1960], 9169410[1961]");
}

TEST(CountryTest, ParseYears)
{
    EXPECT_EQ(parseYears("Country Name;Country Code;1960;1961;1962"), (std::vector<int>{1960, 1961, 1962}));
}

TEST(CountryTest, ParseCountry)
{
    const Country country = parseCountry("Afghanistan;AFG;8996973;9169410", {1960, 1961});
    EXPECT_EQ(country.name, "Afghanistan");
    EXPECT_EQ(country.code, "AFG");
    EXPECT_EQ(country.yearPopulation, (std::map<int, long long>{{1960, 8996973}, {1961, 9169410}}));
}

TEST(CountryTest, ParseCountryWithoutData)
{
    const Country country = parseCountry("Eritrea;ERI;1007590;;1060486", {1960, 1961, 1962});
    EXPECT_EQ(country.yearPopulation, (std::map<int, long long>{{1960, 1007590}, {1962, 1060486}}));
}

TEST(CountryTest, ParseCountries)
{
    const std::vector<Country> countries = parseCountries({
        "Country Name;Country Code;1960;1961",
        "Afghanistan;AFG;8996973;9169410",
        "Albania;ALB;1608800;1659800",
    });
    ASSERT_EQ(countries.size(), 2U);
    EXPECT_EQ(countries[0].code, "AFG");
    EXPECT_EQ(countries[1].name, "Albania");
    EXPECT_EQ(countries[1].yearPopulation.at(1961), 1659800);
}
