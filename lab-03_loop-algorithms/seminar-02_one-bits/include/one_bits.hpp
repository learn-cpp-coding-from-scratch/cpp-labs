#ifndef ONE_BITS_HPP
#define ONE_BITS_HPP

/// Количество единиц в двоичной записи числа number; у отрицательного числа — в дополнительном коде,
/// включая знаковый бит. Без перевода в беззнаковый тип (static_cast, (unsigned), std::bit_cast),
/// std::popcount и std::bitset.
int countOneBits(int number);

#endif // ONE_BITS_HPP
