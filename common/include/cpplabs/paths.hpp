#ifndef CPPLABS_PATHS_HPP
#define CPPLABS_PATHS_HPP

#include <filesystem>

namespace cpplabs {

// папка, в которой лежит исполняемый файл запущенной программы (абсолютный путь).
// Не зависит от текущей папки: программу можно запустить из любой папки или перенести.
// Путь узнаётся у операционной системы (Windows, macOS, Linux); если это не удалось —
// возвращается текущая папка
std::filesystem::path executableDirectory();

// папка data рядом с исполняемым файлом: executableDirectory() / "data".
// Туда сборка копирует папку data/ задачи (add_task_data в CMakeLists.txt задачи)
std::filesystem::path dataDirectory();

} // namespace cpplabs

#endif // CPPLABS_PATHS_HPP
