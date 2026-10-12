#include <cpplabs/io.hpp>

#include <string>

namespace cpplabs {

int readNumber(const std::string& prompt, std::istream& in, std::ostream& out)
{
    out << prompt;
    int number = 0;
    in >> number;
    return number;
}

} // namespace cpplabs
