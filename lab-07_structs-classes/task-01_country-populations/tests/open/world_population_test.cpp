#include <filesystem>
#include <fstream>
#include <map>
#include <sstream>
#include <string>

#include <gtest/gtest.h>

#include "world_population.hpp"

namespace {

std::filesystem::path temporaryPath()
{
    const auto* test = ::testing::UnitTest::GetInstance()->current_test_info();
    const std::string name =
        std::string("country_populations_") + test->test_suite_name() + "_" + test->name() + ".csv";
    const std::filesystem::path path = std::filesystem::temp_directory_path() / name;
    // Файл от прошлого запуска удаляется: иначе тест мог бы прочитать его вместо нового
    std::filesystem::remove(path);
    return path;
}

std::string readText(const std::filesystem::path& path)
{
    std::ifstream in(path);
    std::ostringstream text;
    text << in.rdbuf();
    return text.str();
}

} // namespace

TEST(WorldPopulationTest, ReadCountryPopulationFromFile)
{
    const auto path = temporaryPath();
    std::ofstream(path) << "Country Name;Country Code;1960;1961\n"
                           "Afghanistan;AFG;8996973;9169410\n"
                           "Albania;ALB;1608800;1659800\n";
    WorldPopulation world;
    world.readCountryPopulationFromFile(path);
    ASSERT_EQ(world.countries.size(), 2U);
    EXPECT_EQ(world.countries[0].toString(), "Afghanistan (AFG): 8996973[1960], 9169410[1961]");
}

TEST(WorldPopulationTest, CalcWorldPopulation)
{
    WorldPopulation world;
    world.countries = {
        {"A", "AAA", {{1960, 100}, {1961, 200}}},
        {"B", "BBB", {{1961, 20}}}, // нет данных за 1960
    };
    world.calcWorldPopulation();
    EXPECT_EQ(world.yearPopulation, (std::map<int, long long>{{1960, 100}, {1961, 220}}));
}

TEST(WorldPopulationTest, WriteWorldPopulation)
{
    WorldPopulation world;
    world.yearPopulation = {{1960, 3014710265}, {1961, 3055350225}};
    std::ostringstream out;
    world.writeWorldPopulation(out);
    EXPECT_EQ(out.str(), "1960;1961\n3014710265;3055350225\n");
}

TEST(WorldPopulationTest, WriteWorldPopulationToFile)
{
    WorldPopulation world;
    world.yearPopulation = {{1960, 3}, {1961, 5}};
    const auto path = temporaryPath();
    world.writeWorldPopulationToFile(path);
    EXPECT_EQ(readText(path), "1960;1961\n3;5\n");
}

// Сверка с Excel: сумма столбца 2018 в файле data/world_population_1960-2018.csv
TEST(WorldPopulationTest, DataFileTotal)
{
    WorldPopulation world;
    world.readCountryPopulationFromFile(std::filesystem::path(TASK_DATA_DIRECTORY) / "world_population_1960-2018.csv");
    world.calcWorldPopulation();
    EXPECT_EQ(world.countries.size(), 217U);
    EXPECT_EQ(world.yearPopulation[2018], 7567243296);
}
