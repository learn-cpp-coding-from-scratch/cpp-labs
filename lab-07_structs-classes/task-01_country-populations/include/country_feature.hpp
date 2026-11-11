#ifndef COUNTRY_FEATURE_HPP
#define COUNTRY_FEATURE_HPP

#include <array>
#include <filesystem>
#include <ostream>
#include <string>
#include <vector>

/// Группа дохода страны по классификации Всемирного банка.
enum class IncomeGroup {
    HIGH,          // "High income"
    UPPER_MIDDLE,  // "Upper middle income"
    LOWER_MIDDLE,  // "Lower middle income"
    LOW            // "Low income"
};

/// Все группы дохода — для перебора в цикле.
inline constexpr std::array INCOME_GROUPS{IncomeGroup::HIGH, IncomeGroup::UPPER_MIDDLE,
                                          IncomeGroup::LOWER_MIDDLE, IncomeGroup::LOW};

/// Группа дохода по её названию в файле countries.csv: "Low income" → IncomeGroup::LOW.
/// Для другого текста — исключение std::invalid_argument.
IncomeGroup parseIncomeGroup(const std::string& text);

/// Название группы дохода, как в файле countries.csv: IncomeGroup::LOW → "Low income".
std::string toString(IncomeGroup incomeGroup);

/// Характеристики страны — строка файла countries.csv: код страны, регион, группа дохода.
class CountryFeature {
public:
    CountryFeature() = default;
    CountryFeature(std::string code, std::string region, IncomeGroup incomeGroup);

    [[nodiscard]] const std::string& getCode() const;
    [[nodiscard]] const std::string& getRegion() const;
    [[nodiscard]] IncomeGroup getIncomeGroup() const;

private:
    std::string code_;                         // "AFG"
    std::string region_;                       // "South Asia"
    IncomeGroup incomeGroup_ = IncomeGroup::LOW;
};

/// Выводит характеристики страны: "AFG: South Asia, Low income".
std::ostream& operator<<(std::ostream& out, const CountryFeature& feature);

/// Характеристики страны из строки файла countries.csv "код;регион;группа дохода;название":
/// "AFG;South Asia;Low income;Afghanistan" → {"AFG", "South Asia", IncomeGroup::LOW};
/// название страны не хранится — оно есть в файле населения.
/// Если полей меньше трёх или группа дохода неизвестна — исключение std::invalid_argument.
CountryFeature parseCountryFeature(const std::string& line);

/// Характеристики стран из строк файла countries.csv: первая строка — заголовок, она пропускается,
/// пустые строки тоже; порядок — как в файле.
std::vector<CountryFeature> parseCountryFeatures(const std::vector<std::string>& lines);

/// Читает характеристики стран из файла countries.csv (FileReader::read, затем parseCountryFeatures).
std::vector<CountryFeature> readCountryFeatureFromFile(const std::filesystem::path& file);

#endif // COUNTRY_FEATURE_HPP
