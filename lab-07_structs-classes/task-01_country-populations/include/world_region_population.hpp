#ifndef WORLD_REGION_POPULATION_HPP
#define WORLD_REGION_POPULATION_HPP

#include <map>
#include <string>
#include <vector>

#include "world_country.hpp"

/// Население одного региона по годам.
class WorldRegionPopulation {
public:
    WorldRegionPopulation() = default;
    explicit WorldRegionPopulation(std::string region);

    [[nodiscard]] const std::string& getRegion() const;
    [[nodiscard]] const std::map<int, long long>& getYearPopulation() const;

    /// Население региона по годам: для каждого года — сумма по странам региона (из countries),
    /// у которых есть данные за этот год. Прежнее значение заменяется.
    void calcWorldRegionPopulation(const std::vector<WorldCountry>& countries);

private:
    std::string region_;                        // "South Asia"
    std::map<int, long long> yearPopulation_;   // год → население региона
};

#endif // WORLD_REGION_POPULATION_HPP
