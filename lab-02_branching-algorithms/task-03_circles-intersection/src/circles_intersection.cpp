#include <cassert>
#include <cmath>
#include <iostream>

// результат countIntersections, если окружности совпадают
constexpr int INFINITELY_MANY = -1;

// объявление функций: окружности с центрами (x0, y0), (x1, y1) и радиусами r0, r1 > 0;
// расстояния сравниваются с точностью 1e-9
int countIntersections(double x0, double y0, double r0, double x1, double y1, double r1); // 0, 1, 2 или INFINITELY_MANY
// координаты точки пересечения: side = 1 — одна точка, side = -1 — другая (при касании совпадают);
// предусловие: countIntersections(...) равно 1 или 2
double intersectionX(double x0, double y0, double r0, double x1, double y1, double r1, int side);
double intersectionY(double x0, double y0, double r0, double x1, double y1, double r1, int side);
// TODO: при необходимости объявите вспомогательные функции

// функции тестирования
// NOLINTBEGIN(readability-magic-numbers): в проверках ожидаемые значения записываются числами
void testCountIntersections()
{
    assert(countIntersections(0, 0, 5, 6, 0, 5) == 2);
    // TODO: добавьте проверки — далеко, касание внешнее и внутреннее, совпадение, одна внутри другой
}

void testIntersectionPoints()
{
    // (0, 0) и (6, 0), радиусы 5: точки (3, 4) и (3, -4) — в любом порядке
    assert(std::abs(intersectionX(0, 0, 5, 6, 0, 5, 1) - 3) < 1e-9);
    // TODO: добавьте проверки — обе точки, касание, центры не на оси
}
// NOLINTEND(readability-magic-numbers)

// точка входа
int main()
{
    // тестирование работы функций
    testCountIntersections();
    testIntersectionPoints();

    // TODO: ввод двух окружностей, вывод числа и координат точек пересечения
    return 0;
}

// определение функций
constexpr double EPSILON = 1e-9;

int countIntersections(double x0, double y0, double r0, double x1, double y1, double r1)
{
    // TODO: напишите решение
    return {};
}

// Точки пересечения лежат на перпендикуляре к линии центров: его основание — на расстоянии
// along от центра 0, а точки отстоят от основания на halfChord в обе стороны
double intersectionX(double x0, double y0, double r0, double x1, double y1, double r1, int side)
{
    // TODO: напишите решение
    return {};
}

double intersectionY(double x0, double y0, double r0, double x1, double y1, double r1, int side)
{
    // TODO: напишите решение
    return {};
}
// TODO: при необходимости определите вспомогательные функции
