#include <map>
#include <vector>

#include <gtest/gtest.h>

#include "world_country.hpp"

TEST(WorldCountryTest, Constructor)
{
    const WorldCountry country("Afghanistan", CountryFeature("AFG", "South Asia", IncomeGroup::LOW),
                               {{1960, 8996973}});
    EXPECT_EQ(country.getName(), "Afghanistan");
    EXPECT_EQ(country.getFeature().getRegion(), "South Asia");
    EXPECT_EQ(country.getYearPopulation(), (std::map<int, long long>{{1960, 8996973}}));
}

TEST(WorldCountryTest, MakeWorldCountries)
{
    const std::vector<Country> countries{
        {"Afghanistan", "AFG", {{1960, 8996973}}},
        {"Albania", "ALB", {{1960, 1608800}}},
    };
    // Характеристики — в другом порядке: страны объединяются по коду
    const std::vector<CountryFeature> features{
        {"ALB", "Europe & Central Asia", IncomeGroup::UPPER_MIDDLE},
        {"AFG", "South Asia", IncomeGroup::LOW},
    };
    const std::vector<WorldCountry> worldCountries = makeWorldCountries(countries, features);
    ASSERT_EQ(worldCountries.size(), 2U);
    EXPECT_EQ(worldCountries[0].getName(), "Afghanistan");
    EXPECT_EQ(worldCountries[0].getFeature().getRegion(), "South Asia");
    EXPECT_EQ(worldCountries[1].getName(), "Albania");
    EXPECT_EQ(worldCountries[1].getFeature().getIncomeGroup(), IncomeGroup::UPPER_MIDDLE);
    EXPECT_EQ(worldCountries[1].getYearPopulation().at(1960), 1608800);
}
