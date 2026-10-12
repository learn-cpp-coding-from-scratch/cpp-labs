#ifndef LATTICE_POINTS_HPP
#define LATTICE_POINTS_HPP

/// Количество пар целых неотрицательных чисел (x, y), для которых x² + y² < n².
/// Только целочисленные операции (без sqrt и double). Если n <= 0, таких пар нет: 0.
long long countLatticePoints(int n);

#endif // LATTICE_POINTS_HPP
