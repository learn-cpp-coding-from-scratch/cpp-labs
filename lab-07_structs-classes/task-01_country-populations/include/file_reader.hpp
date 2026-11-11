#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <filesystem>
#include <string>
#include <vector>

/// Чтение текстового файла в коллекцию строк. Строки разбирают отдельные функции
/// (parseCountries, parseCountryFeatures): их можно проверить тестами на строках, без файлов.
class FileReader {
public:
    /// Читает все строки файла по порядку. Символ '\r' в конце строки (концы строк Windows "\r\n")
    /// отбрасывается. Если файл не открывается — исключение std::runtime_error с именем файла.
    static std::vector<std::string> read(const std::filesystem::path& file);
};

/// Делит строку на поля по разделителю; пустые поля сохраняются, в том числе последнее:
/// split("a;;b;", ';') → {"a", "", "b", ""}, split("", ';') → {""}.
std::vector<std::string> split(const std::string& line, char delimiter);

#endif // FILE_READER_HPP
