#ifndef COUNTRY_HPP
#define COUNTRY_HPP

#include <map>
#include <ostream>
#include <string>
#include <vector>

/// Страна и её население по годам — строка файла world_population_1960-2018.csv.
struct Country {
    std::string name;                         // "Afghanistan"
    std::string code;                         // "AFG"
    std::map<int, long long> yearPopulation;  // год → население; лет без данных в map нет

    // [[nodiscard]]: компилятор предупредит, если результат функции не использован —
    // вызов константной функции-члена без использования результата бесполезен
    /// Страна в виде строки: "Afghanistan (AFG): 8996973[1960], 9169410[1961]";
    /// годы — по возрастанию; без данных о населении — "Afghanistan (AFG):".
    [[nodiscard]] std::string toString() const;
};

/// Выводит страну в том же виде, что toString().
std::ostream& operator<<(std::ostream& out, const Country& country);

/// Годы из строки заголовка файла населения:
/// "Country Name;Country Code;1960;1961" → {1960, 1961}.
std::vector<int> parseYears(const std::string& header);

/// Страна из строки файла населения; years — годы из заголовка, по одному на каждое поле с населением.
/// Пустое поле — нет данных за год:
/// "Eritrea;ERI;1007590;;1060486" при years = {1960, 1961, 1962} →
/// {"Eritrea", "ERI", {{1960, 1007590}, {1962, 1060486}}}.
/// Если полей не 2 + years.size() — исключение std::invalid_argument.
Country parseCountry(const std::string& line, const std::vector<int>& years);

/// Страны из строк файла населения: первая строка — заголовок с годами, остальные — страны
/// в порядке файла; пустые строки пропускаются. Для пустого списка строк — пустой результат.
std::vector<Country> parseCountries(const std::vector<std::string>& lines);

#endif // COUNTRY_HPP
