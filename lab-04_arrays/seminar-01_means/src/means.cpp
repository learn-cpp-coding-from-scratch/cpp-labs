// Пример решения: задача разобрана на семинаре, решение дано в заготовке целиком

#include "means.hpp"

#include <cmath>

std::pair<double, double> findMeans(const std::vector<double>& numbers)
{
    // Среднее геометрическое k чисел — корень степени k из их произведения. Произведение
    // больших чисел выходит за пределы double, поэтому складываются логарифмы:
    // ln(среднего геометрического) = (ln x1 + … + ln xk) / k
    double logSum = 0.0;
    int positiveCount = 0;
    double negativeSum = 0.0;
    int negativeCount = 0;
    for (const double number : numbers) {
        if (number > 0) {
            logSum += std::log(number);
            ++positiveCount;
        } else if (number < 0) {
            negativeSum += number;
            ++negativeCount;
        }
    }

    double geometricMean = 0.0;
    if (positiveCount > 0) {
        geometricMean = std::exp(logSum / positiveCount);
    }
    double arithmeticMean = 0.0;
    if (negativeCount > 0) {
        arithmeticMean = negativeSum / negativeCount;
    }
    return {geometricMean, arithmeticMean};
}
