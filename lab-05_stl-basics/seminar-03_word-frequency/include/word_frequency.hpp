#ifndef WORD_FREQUENCY_HPP
#define WORD_FREQUENCY_HPP

#include <map>
#include <string>
#include <vector>

/// Частотный словарь слов строк lines: слово → сколько раз оно встречается.
/// Слова отделяются друг от друга пробельными символами; знаки препинания (символы, для которых
/// std::ispunct истинно: , . ! ? - ' " и др.) из слов удаляются: "end." и "end" — одно слово,
/// "don't" → "dont". Последовательность из одних знаков препинания ("-", "...") словом не считается.
/// Знаками препинания считаются только символы ASCII: буквы кириллицы и тире «—» в UTF-8 не удаляются.
/// Регистр букв не меняется: "The" и "the" — разные слова.
/// {"The cat, the dog.", "The end!"} → {{"The", 2}, {"cat", 1}, {"dog", 1}, {"end", 1}, {"the", 1}}.
/// Строки файла читает main — пример файла: data/text.txt.
std::map<std::string, int> buildWordFrequency(const std::vector<std::string>& lines);

#endif // WORD_FREQUENCY_HPP
