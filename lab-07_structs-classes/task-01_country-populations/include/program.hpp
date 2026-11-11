#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <filesystem>
#include <ostream>
#include <string>
#include <vector>

#include "country_feature.hpp"
#include "world_country.hpp"
#include "world_region_population.hpp"

/// Программа: страны мира с характеристиками, выборки стран и население регионов.
class Program {
public:
    /// Работа программы целиком; вызывается из функции main.
    static int main();

    /// Читает файл населения и файл характеристик стран, объединяет их (makeWorldCountries),
    /// сохраняет в программе и возвращает страны. Прежние данные программы заменяются,
    /// население регионов сбрасывается.
    const std::vector<WorldCountry>& readCountryPopulationFromFile(const std::filesystem::path& populationFile,
                                                                   const std::filesystem::path& featuresFile);

    /// Страны с группой дохода incomeGroup — в порядке хранения в программе.
    [[nodiscard]] std::vector<WorldCountry> findCountriesByIncome(IncomeGroup incomeGroup) const;

    /// Регионы всех прочитанных характеристик стран, каждый один раз, по алфавиту.
    [[nodiscard]] std::vector<std::string> findUniqueRegion() const;

    /// Названия стран региона region — в порядке хранения в программе; нет таких стран — пустой результат.
    [[nodiscard]] std::vector<std::string> findCountriesByRegion(const std::string& region) const;

    /// Население регионов по годам: по объекту WorldRegionPopulation на каждый регион
    /// из findUniqueRegion(), в том же порядке. Сохраняет результат в программе и возвращает его.
    const std::vector<WorldRegionPopulation>& calcRegionPopulations();

    /// Записывает население регионов, посчитанное calcRegionPopulations, с разделителем ';':
    /// первая строка — "Region" и годы всех регионов по возрастанию, затем строка на каждый регион —
    /// название и население по этим годам (нет данных за год — пустое поле):
    /// "Region;1960;1961\nEast Asia & Pacific;1030256390;1033472284\n…".
    /// Если население регионов не посчитано — одна строка "Region\n".
    void writeWorldRegionPopulation(std::ostream& out) const;

    /// То же, что writeWorldRegionPopulation, в файл. Если файл не создаётся — исключение std::runtime_error.
    void writeWorldRegionPopulationToFile(const std::filesystem::path& file) const;

private:
    std::vector<CountryFeature> countryFeatures_;
    std::vector<WorldCountry> worldCountries_;
    std::vector<WorldRegionPopulation> regionPopulations_;
};

#endif // PROGRAM_HPP
