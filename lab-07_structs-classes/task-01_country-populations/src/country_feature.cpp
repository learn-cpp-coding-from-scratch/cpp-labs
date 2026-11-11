#include "country_feature.hpp"

#include <utility>

// TODO: напишите решение

IncomeGroup parseIncomeGroup(const std::string& text)
{
    // TODO: напишите решение
    return {};
}

std::string toString(IncomeGroup incomeGroup)
{
    // TODO: напишите решение
    return {};
}

CountryFeature::CountryFeature(std::string code, std::string region, IncomeGroup incomeGroup)
    : code_(std::move(code)), region_(std::move(region)), incomeGroup_(incomeGroup)
{
}

const std::string& CountryFeature::getCode() const
{
    return code_;
}

const std::string& CountryFeature::getRegion() const
{
    return region_;
}

IncomeGroup CountryFeature::getIncomeGroup() const
{
    return incomeGroup_;
}

std::ostream& operator<<(std::ostream& out, const CountryFeature& feature)
{
    // TODO: напишите решение
    return out;
}

CountryFeature parseCountryFeature(const std::string& line)
{
    // TODO: напишите решение
    return {};
}

std::vector<CountryFeature> parseCountryFeatures(const std::vector<std::string>& lines)
{
    std::vector<CountryFeature> features;
    // TODO: напишите решение
    return features;
}

std::vector<CountryFeature> readCountryFeatureFromFile(const std::filesystem::path& file)
{
    // TODO: напишите решение
    return {};
}
