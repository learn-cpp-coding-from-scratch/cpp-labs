#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "program.hpp"

namespace {

std::filesystem::path temporaryPath(const std::string& suffix)
{
    const auto* test = ::testing::UnitTest::GetInstance()->current_test_info();
    const std::string name = std::string("country_populations_") + test->test_suite_name() + "_" + test->name() +
                             "_" + suffix + ".csv";
    const std::filesystem::path path = std::filesystem::temp_directory_path() / name;
    // Файл от прошлого запуска удаляется: иначе тест мог бы прочитать его вместо нового
    std::filesystem::remove(path);
    return path;
}

// Программа с четырьмя странами двух регионов, прочитанными из временных файлов
Program readSmallProgram()
{
    const auto populationFile = temporaryPath("population");
    std::ofstream(populationFile) << "Country Name;Country Code;1960;1961\n"
                                     "Alpha;AAA;100;200\n"
                                     "Beta;BBB;1000;2000\n"
                                     "Gamma;CCC;;20\n"
                                     "Delta;DDD;5;6\n";
    const auto featuresFile = temporaryPath("features");
    std::ofstream(featuresFile) << "Country Code;Region;IncomeGroup;Country Name\n"
                                   "AAA;North;High income;Alpha\n"
                                   "BBB;East & South;Low income;Beta\n"
                                   "CCC;North;Low income;Gamma\n"
                                   "DDD;East & South;Upper middle income;Delta\n";
    Program program;
    program.readCountryPopulationFromFile(populationFile, featuresFile);
    return program;
}

std::vector<std::string> names(const std::vector<WorldCountry>& countries)
{
    std::vector<std::string> result;
    for (const WorldCountry& country : countries) {
        result.push_back(country.getName());
    }
    return result;
}

} // namespace

TEST(ProgramTest, ReadCountryPopulationFromFile)
{
    const auto populationFile = temporaryPath("population");
    std::ofstream(populationFile) << "Country Name;Country Code;1960\nAfghanistan;AFG;8996973\n";
    const auto featuresFile = temporaryPath("features");
    std::ofstream(featuresFile) << "Country Code;Region;IncomeGroup;Country Name\n"
                                   "AFG;South Asia;Low income;Afghanistan\n";
    Program program;
    const std::vector<WorldCountry>& countries = program.readCountryPopulationFromFile(populationFile, featuresFile);
    ASSERT_EQ(countries.size(), 1U);
    EXPECT_EQ(countries[0].getName(), "Afghanistan");
    EXPECT_EQ(countries[0].getFeature().getRegion(), "South Asia");
    EXPECT_EQ(countries[0].getYearPopulation().at(1960), 8996973);
}

TEST(ProgramTest, FindCountriesByIncome)
{
    const Program program = readSmallProgram();
    EXPECT_EQ(names(program.findCountriesByIncome(IncomeGroup::LOW)), (std::vector<std::string>{"Beta", "Gamma"}));
    EXPECT_TRUE(program.findCountriesByIncome(IncomeGroup::LOWER_MIDDLE).empty());
}

TEST(ProgramTest, FindUniqueRegion)
{
    const Program program = readSmallProgram();
    EXPECT_EQ(program.findUniqueRegion(), (std::vector<std::string>{"East & South", "North"}));
}

TEST(ProgramTest, FindCountriesByRegion)
{
    const Program program = readSmallProgram();
    EXPECT_EQ(program.findCountriesByRegion("North"), (std::vector<std::string>{"Alpha", "Gamma"}));
}

TEST(ProgramTest, CalcRegionPopulations)
{
    Program program = readSmallProgram();
    const std::vector<WorldRegionPopulation>& regions = program.calcRegionPopulations();
    ASSERT_EQ(regions.size(), 2U);
    EXPECT_EQ(regions[0].getRegion(), "East & South");
    EXPECT_EQ(regions[0].getYearPopulation(), (std::map<int, long long>{{1960, 1005}, {1961, 2006}}));
    EXPECT_EQ(regions[1].getRegion(), "North");
    EXPECT_EQ(regions[1].getYearPopulation(), (std::map<int, long long>{{1960, 100}, {1961, 220}}));
}

TEST(ProgramTest, WriteWorldRegionPopulation)
{
    Program program = readSmallProgram();
    program.calcRegionPopulations();
    std::ostringstream out;
    program.writeWorldRegionPopulation(out);
    EXPECT_EQ(out.str(), "Region;1960;1961\n"
                         "East & South;1005;2006\n"
                         "North;100;220\n");
}
