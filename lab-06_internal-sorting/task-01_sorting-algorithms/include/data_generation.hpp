#ifndef DATA_GENERATION_HPP
#define DATA_GENERATION_HPP

#include <array>
#include <cstddef>
#include <filesystem>
#include <string>
#include <vector>

/// Порядок элементов во входных данных.
enum class DataOrder { ASCENDING, DESCENDING, RANDOM };

/// Набор входных данных: порядок элементов и номер случайного набора (1, 2, 3; у упорядоченных — 0).
struct Dataset {
    DataOrder order = DataOrder::RANDOM;
    int randomSetNumber = 0;
};

/// Размеры массивов в эксперименте.
inline constexpr std::array<std::size_t, 4> EXPERIMENT_SIZES{10, 100, 1000, 10000};

/// Случайные значения — в отрезке [-MAX_RANDOM_VALUE, MAX_RANDOM_VALUE].
inline constexpr int MAX_RANDOM_VALUE = 1000000;

/// Наборы эксперимента по порядку строк сводной таблицы:
/// по возрастанию, по убыванию, случайные 1, 2, 3.
std::vector<Dataset> experimentDatasets();

/// Массив из size элементов:
///   ASCENDING  — 1, 2, …, size;
///   DESCENDING — size, size - 1, …, 1;
///   RANDOM     — случайные числа из [-MAX_RANDOM_VALUE, MAX_RANDOM_VALUE]; генератор
///                инициализируется по size и randomSetNumber, поэтому при каждом запуске
///                программы набор один и тот же, а наборы с разными номерами различаются.
std::vector<int> generateData(std::size_t size, const Dataset& dataset);

/// Имя набора для файлов: "ascending", "descending", "random_1".
std::string datasetName(const Dataset& dataset);

/// Название набора для сводной таблицы: "по возрастанию", "по убыванию", "случайный 1".
std::string datasetTitle(const Dataset& dataset);

/// Имя входного файла: (10, random 1) → "input_10_int_random_1.txt",
/// (1000, ascending) → "input_1000_int_ascending.txt".
std::string inputFileName(std::size_t size, const Dataset& dataset);

/// Создаёт папку directory (если её нет) и записывает в неё входные файлы для всех размеров
/// EXPERIMENT_SIZES и наборов experimentDatasets() — 20 файлов; возвращает их пути.
std::vector<std::filesystem::path> writeInputFiles(const std::filesystem::path& directory);

#endif // DATA_GENERATION_HPP
