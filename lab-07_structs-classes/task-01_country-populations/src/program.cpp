#include "program.hpp"

// TODO: напишите решение

int Program::main()
{
    // TODO: напишите решение
    return 0;
}

const std::vector<WorldCountry>& Program::readCountryPopulationFromFile(const std::filesystem::path& populationFile,
                                                                        const std::filesystem::path& featuresFile)
{
    // TODO: напишите решение
    return worldCountries_;
}

std::vector<WorldCountry> Program::findCountriesByIncome(IncomeGroup incomeGroup) const
{
    std::vector<WorldCountry> found;
    // TODO: напишите решение
    return found;
}

std::vector<std::string> Program::findUniqueRegion() const
{
    // TODO: напишите решение
    return {};
}

std::vector<std::string> Program::findCountriesByRegion(const std::string& region) const
{
    std::vector<std::string> names;
    // TODO: напишите решение
    return names;
}

const std::vector<WorldRegionPopulation>& Program::calcRegionPopulations()
{
    // TODO: напишите решение
    return regionPopulations_;
}

void Program::writeWorldRegionPopulation(std::ostream& out) const
{
    // TODO: напишите решение
}

void Program::writeWorldRegionPopulationToFile(const std::filesystem::path& file) const
{
    // TODO: напишите решение
}
