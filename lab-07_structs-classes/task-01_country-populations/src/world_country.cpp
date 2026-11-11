#include "world_country.hpp"

#include <utility>

// TODO: напишите решение

WorldCountry::WorldCountry(std::string name, CountryFeature feature, std::map<int, long long> yearPopulation)
    : name_(std::move(name)), feature_(std::move(feature)), yearPopulation_(std::move(yearPopulation))
{
}

const std::string& WorldCountry::getName() const
{
    return name_;
}

const CountryFeature& WorldCountry::getFeature() const
{
    return feature_;
}

const std::map<int, long long>& WorldCountry::getYearPopulation() const
{
    return yearPopulation_;
}

std::vector<WorldCountry> makeWorldCountries(const std::vector<Country>& countries,
                                             const std::vector<CountryFeature>& features)
{
    std::vector<WorldCountry> worldCountries;
    // TODO: напишите решение
    return worldCountries;
}
