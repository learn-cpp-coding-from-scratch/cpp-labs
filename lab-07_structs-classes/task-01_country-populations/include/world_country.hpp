#ifndef WORLD_COUNTRY_HPP
#define WORLD_COUNTRY_HPP

#include <map>
#include <string>
#include <vector>

#include "country.hpp"
#include "country_feature.hpp"

/// Страна вместе с характеристиками и населением по годам.
class WorldCountry {
public:
    WorldCountry() = default;
    WorldCountry(std::string name, CountryFeature feature, std::map<int, long long> yearPopulation);

    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] const CountryFeature& getFeature() const;
    [[nodiscard]] const std::map<int, long long>& getYearPopulation() const;

private:
    std::string name_;
    CountryFeature feature_;
    std::map<int, long long> yearPopulation_;  // год → население
};

/// Объединяет страны с их характеристиками по коду страны (Country::code = CountryFeature::getCode()).
/// Порядок — как в countries; страна, для которой нет характеристик, пропускается.
std::vector<WorldCountry> makeWorldCountries(const std::vector<Country>& countries,
                                             const std::vector<CountryFeature>& features);

#endif // WORLD_COUNTRY_HPP
