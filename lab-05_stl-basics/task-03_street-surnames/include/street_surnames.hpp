#ifndef STREET_SURNAMES_HPP
#define STREET_SURNAMES_HPP

#include <map>
#include <string>
#include <utility>
#include <vector>

/// Для каждой улицы — сколько различных фамилий на ней живёт.
/// residents — пары {улица, фамилия}. В словаре улицы упорядочены лексикографически.
/// {{"lenina", "ivanov"}, {"gorkogo", "petrov"}, {"lenina", "sidorov"}, {"lenina", "ivanov"}}
/// → {{"gorkogo", 1}, {"lenina", 2}}.
std::map<std::string, int> countSurnamesByStreet(const std::vector<std::pair<std::string, std::string>>& residents);

#endif // STREET_SURNAMES_HPP
