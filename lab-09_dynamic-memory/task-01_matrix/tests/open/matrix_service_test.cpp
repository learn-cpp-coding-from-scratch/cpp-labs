#include <cstddef>
#include <stdexcept>

#include <gtest/gtest.h>

#include "matrix.hpp"
#include "matrix_service.hpp"

namespace {

// Матрицы одного размера, элементы равны с точностью 1e-9
::testing::AssertionResult nearlyEqual(const Matrix<double>& actual, const Matrix<double>& expected)
{
    if (actual.rows() != expected.rows() || actual.columns() != expected.columns()) {
        return ::testing::AssertionFailure() << "sizes differ: " << actual.rows() << "x" << actual.columns()
                                             << " vs " << expected.rows() << "x" << expected.columns();
    }
    for (std::size_t i = 0; i < actual.rows(); ++i) {
        for (std::size_t j = 0; j < actual.columns(); ++j) {
            const double difference = actual(i, j) - expected(i, j);
            if (difference > 1e-9 || difference < -1e-9) {
                return ::testing::AssertionFailure() << "element (" << i << ", " << j << "): " << actual(i, j)
                                                     << " vs " << expected(i, j);
            }
        }
    }
    return ::testing::AssertionSuccess();
}

} // namespace

TEST(MatrixServiceTest, OperationAnalogues)
{
    const Matrix<int> a{{1, 2}, {3, 4}};
    const Matrix<int> b{{4, 3}, {2, 1}};
    EXPECT_EQ(MatrixService::add(a, b), a + b);
    EXPECT_EQ(MatrixService::subtract(a, b), a - b);
    EXPECT_EQ(MatrixService::multiply(a, b), a * b);
    EXPECT_EQ(MatrixService::multiply(a, 3), a * 3);
}

TEST(MatrixServiceTest, Transpose)
{
    EXPECT_EQ(MatrixService::transpose(Matrix<int>{{1, 2, 3}}), (Matrix<int>{{1}, {2}, {3}}));
    EXPECT_EQ(MatrixService::transpose(Matrix<int>{{1, 2}, {3, 4}}), (Matrix<int>{{1, 3}, {2, 4}}));
}

TEST(MatrixServiceTest, RotateCounterclockwise)
{
    const Matrix<int> m{{1, 2}, {3, 4}};
    EXPECT_EQ(MatrixService::rotate(m, 90), (Matrix<int>{{2, 4}, {1, 3}}));
    EXPECT_EQ(MatrixService::rotate(m, 180), (Matrix<int>{{4, 3}, {2, 1}}));
    EXPECT_EQ(MatrixService::rotate(m, 270), (Matrix<int>{{3, 1}, {4, 2}}));
}

TEST(MatrixServiceTest, RotateClockwise)
{
    const Matrix<int> m{{1, 2}, {3, 4}};
    EXPECT_EQ(MatrixService::rotate(m, -90), (Matrix<int>{{3, 1}, {4, 2}}));
    EXPECT_EQ(MatrixService::rotate(m, -180), (Matrix<int>{{4, 3}, {2, 1}}));
    EXPECT_EQ(MatrixService::rotate(m, -270), (Matrix<int>{{2, 4}, {1, 3}}));
}

TEST(MatrixServiceTest, RotateRectangular)
{
    const Matrix<int> m{{1, 2, 3}, {4, 5, 6}};
    EXPECT_EQ(MatrixService::rotate(m, 90), (Matrix<int>{{3, 6}, {2, 5}, {1, 4}}));
    EXPECT_EQ(MatrixService::rotate(m, -90), (Matrix<int>{{4, 1}, {5, 2}, {6, 3}}));
}

TEST(MatrixServiceTest, RotateFullTurnAndBadAngle)
{
    const Matrix<int> m{{1, 2}, {3, 4}};
    EXPECT_EQ(MatrixService::rotate(m, 360), m);
    EXPECT_EQ(MatrixService::rotate(m, 0), m);
    EXPECT_THROW(MatrixService::rotate(m, 45), std::invalid_argument);
}

TEST(MatrixServiceTest, Determinant)
{
    EXPECT_NEAR(MatrixService::determinant(Matrix<double>{{1, 2}, {3, 4}}), -2.0, 1e-9);
    EXPECT_NEAR(MatrixService::determinant(Matrix<double>{{2, 0, 0}, {0, 3, 0}, {0, 0, 4}}), 24.0, 1e-9);
    EXPECT_NEAR(MatrixService::determinant(Matrix<double>{{1, 2}, {2, 4}}), 0.0, 1e-9);
}

TEST(MatrixServiceTest, Inverse)
{
    const Matrix<double> a{{4, 7}, {2, 6}};
    const Matrix<double> inverse = MatrixService::inverse(a);
    EXPECT_TRUE(nearlyEqual(inverse, Matrix<double>{{0.6, -0.7}, {-0.2, 0.4}}));
    EXPECT_TRUE(nearlyEqual(inverse * a, Matrix<double>::identity(2)));
}

TEST(MatrixServiceTest, SingularMatrixThrows)
{
    EXPECT_THROW(MatrixService::inverse(Matrix<double>{{1, 2}, {2, 4}}), std::domain_error);
    EXPECT_THROW(MatrixService::solve(Matrix<double>{{1, 2}, {2, 4}}, Matrix<double>{{1}, {2}}), std::domain_error);
}

TEST(MatrixServiceTest, NotSquareThrows)
{
    EXPECT_THROW(static_cast<void>(MatrixService::determinant(Matrix<double>(2, 3))), std::invalid_argument);
    EXPECT_THROW(MatrixService::inverse(Matrix<double>(2, 3)), std::invalid_argument);
}

TEST(MatrixServiceTest, Solve)
{
    // 2x + y = 5, x + 3y = 10 → x = 1, y = 3
    const Matrix<double> a{{2, 1}, {1, 3}};
    const Matrix<double> b{{5}, {10}};
    EXPECT_TRUE(nearlyEqual(MatrixService::solve(a, b), Matrix<double>{{1}, {3}}));
}

TEST(MatrixServiceTest, SolveSizesMismatchThrows)
{
    EXPECT_THROW(MatrixService::solve(Matrix<double>{{1, 0}, {0, 1}}, Matrix<double>{{1}}), std::invalid_argument);
}
