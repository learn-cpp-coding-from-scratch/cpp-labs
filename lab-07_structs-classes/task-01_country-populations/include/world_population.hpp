#ifndef WORLD_POPULATION_HPP
#define WORLD_POPULATION_HPP

#include <filesystem>
#include <map>
#include <ostream>
#include <vector>

#include "country.hpp"

/// Страны и население мира по годам.
struct WorldPopulation {
    std::vector<Country> countries;
    std::map<int, long long> yearPopulation;  // год → население всех стран

    /// Читает страны из файла населения (FileReader::read, затем parseCountries);
    /// прежние страны заменяются.
    void readCountryPopulationFromFile(const std::filesystem::path& file);

    /// Население мира по годам: для каждого года — сумма по странам, у которых есть данные за этот год.
    /// Прежнее значение yearPopulation заменяется.
    void calcWorldPopulation();

    /// Записывает yearPopulation двумя строками с разделителем ';' — годы и население:
    /// {{1960, 3014710265}, {1961, 3055350225}} → "1960;1961\n3014710265;3055350225\n";
    /// пустой yearPopulation → "\n\n".
    void writeWorldPopulation(std::ostream& out) const;

    /// То же, что writeWorldPopulation, в файл. Если файл не создаётся — исключение std::runtime_error.
    void writeWorldPopulationToFile(const std::filesystem::path& file) const;
};

#endif // WORLD_POPULATION_HPP
