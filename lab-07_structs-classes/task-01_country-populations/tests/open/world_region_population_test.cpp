#include <map>
#include <vector>

#include <gtest/gtest.h>

#include "world_region_population.hpp"

TEST(WorldRegionPopulationTest, CalcWorldRegionPopulation)
{
    const std::vector<WorldCountry> countries{
        {"A", {"AAA", "Region 1", IncomeGroup::HIGH}, {{1960, 100}, {1961, 200}}},
        {"B", {"BBB", "Region 2", IncomeGroup::LOW}, {{1960, 1000}, {1961, 2000}}},
        {"C", {"CCC", "Region 1", IncomeGroup::LOW}, {{1961, 20}}},
    };
    WorldRegionPopulation regionPopulation("Region 1");
    regionPopulation.calcWorldRegionPopulation(countries);
    EXPECT_EQ(regionPopulation.getRegion(), "Region 1");
    EXPECT_EQ(regionPopulation.getYearPopulation(), (std::map<int, long long>{{1960, 100}, {1961, 220}}));
}
