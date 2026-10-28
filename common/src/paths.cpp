#include <cpplabs/paths.hpp>

#include <cstdint>
#include <string>
#include <system_error>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#endif

namespace cpplabs {

namespace {

// Полный путь к исполняемому файлу; пустой путь, если узнать его не удалось
std::filesystem::path executablePath()
{
#if defined(_WIN32)
    // Широкие символы: путь с русскими буквами читается верно при любой кодовой странице
    std::wstring buffer(MAX_PATH, L'\0');
    while (true) {
        const DWORD length = GetModuleFileNameW(nullptr, buffer.data(), static_cast<DWORD>(buffer.size()));
        if (length == 0) {
            return {};
        }
        if (length < buffer.size()) {
            buffer.resize(length);
            return buffer;
        }
        buffer.resize(buffer.size() * 2); // путь не поместился — буфер побольше
    }
#elif defined(__APPLE__)
    std::uint32_t size = 0;
    _NSGetExecutablePath(nullptr, &size); // первый вызов сообщает нужный размер буфера
    std::string buffer(size, '\0');
    if (_NSGetExecutablePath(buffer.data(), &size) != 0) {
        return {};
    }
    buffer.resize(buffer.find('\0'));
    return buffer;
#elif defined(__linux__)
    std::error_code error;
    std::filesystem::path path = std::filesystem::read_symlink("/proc/self/exe", error);
    return error ? std::filesystem::path() : path;
#else
    return {};
#endif
}

} // namespace

std::filesystem::path executableDirectory()
{
    const std::filesystem::path path = executablePath();
    if (path.empty()) {
        return std::filesystem::current_path();
    }
    // weakly_canonical убирает «.», «..» и символические ссылки (macOS может вернуть путь с ними)
    std::error_code error;
    const std::filesystem::path canonical = std::filesystem::weakly_canonical(path, error);
    return (error ? path : canonical).parent_path();
}

std::filesystem::path dataDirectory()
{
    return executableDirectory() / "data";
}

} // namespace cpplabs
