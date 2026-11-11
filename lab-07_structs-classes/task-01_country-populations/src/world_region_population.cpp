#include "world_region_population.hpp"

#include <utility>

WorldRegionPopulation::WorldRegionPopulation(std::string region) : region_(std::move(region)) {}

const std::string& WorldRegionPopulation::getRegion() const
{
    return region_;
}

const std::map<int, long long>& WorldRegionPopulation::getYearPopulation() const
{
    return yearPopulation_;
}

void WorldRegionPopulation::calcWorldRegionPopulation(const std::vector<WorldCountry>& countries)
{
    // TODO: напишите решение
}
