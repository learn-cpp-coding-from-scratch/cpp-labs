#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

#include <gtest/gtest.h>

#include "matrix.hpp"

namespace {

template <typename T>
std::string toString(const Matrix<T>& matrix)
{
    std::ostringstream out;
    out << matrix;
    return out.str();
}

} // namespace

// 1. Конструкторы и правило пяти

TEST(MatrixTest, DefaultIsEmpty)
{
    const Matrix<int> matrix;
    EXPECT_EQ(matrix.rows(), 0U);
    EXPECT_EQ(matrix.columns(), 0U);
    EXPECT_EQ(toString(matrix), "");
}

TEST(MatrixTest, SizeConstructorFillsWithZeros)
{
    const Matrix<int> matrix(2, 3);
    EXPECT_EQ(matrix.rows(), 2U);
    EXPECT_EQ(matrix.columns(), 3U);
    EXPECT_EQ(toString(matrix), "0 0 0\n0 0 0\n");
}

TEST(MatrixTest, SizeValueConstructor)
{
    EXPECT_EQ(toString(Matrix<int>(2, 2, 7)), "7 7\n7 7\n");
}

TEST(MatrixTest, ZeroSizeThrows)
{
    EXPECT_THROW(Matrix<int>(0, 3), std::invalid_argument);
    EXPECT_THROW(Matrix<int>(3, 0), std::invalid_argument);
}

TEST(MatrixTest, RowList)
{
    const Matrix<int> matrix{{1, 2, 3}, {4, 5, 6}};
    EXPECT_EQ(matrix.rows(), 2U);
    EXPECT_EQ(matrix.columns(), 3U);
    EXPECT_EQ(toString(matrix), "1 2 3\n4 5 6\n");
}

TEST(MatrixTest, RowsOfDifferentLengthThrow)
{
    EXPECT_THROW((Matrix<int>{{1, 2}, {3}}), std::invalid_argument);
}

TEST(MatrixTest, Identity)
{
    EXPECT_EQ(toString(Matrix<int>::identity(2)), "1 0\n0 1\n");
}

TEST(MatrixTest, Diagonal)
{
    EXPECT_EQ(toString(Matrix<int>::diagonal({2, 3})), "2 0\n0 3\n");
}

TEST(MatrixTest, CopyIsDeep)
{
    const Matrix<int> original{{1, 2}};
    Matrix<int> copy = original;
    copy(0, 0) = 9;
    EXPECT_EQ(toString(original), "1 2\n");
    EXPECT_EQ(toString(copy), "9 2\n");
}

TEST(MatrixTest, CopyAssignmentAndSelfAssignment)
{
    const Matrix<int> original{{1, 2}};
    Matrix<int> target(3, 3);
    target = original;
    EXPECT_EQ(toString(target), "1 2\n");
    const Matrix<int>& alias = target;
    target = alias;
    EXPECT_EQ(toString(target), "1 2\n");
}

TEST(MatrixTest, MoveEmptiesSource)
{
    Matrix<int> source{{1, 2}};
    Matrix<int> target = std::move(source);
    EXPECT_EQ(toString(target), "1 2\n");
    EXPECT_EQ(source.rows(), 0U); // NOLINT(bugprone-use-after-move): проверяем состояние после перемещения
    source = std::move(target);   // NOLINT(bugprone-use-after-move)
    EXPECT_EQ(toString(source), "1 2\n");
    EXPECT_EQ(target.rows(), 0U); // NOLINT(bugprone-use-after-move)
}

TEST(MatrixTest, MoveOperationsAreNoexcept)
{
    EXPECT_TRUE(std::is_nothrow_move_constructible_v<Matrix<int>>);
    EXPECT_TRUE(std::is_nothrow_move_assignable_v<Matrix<int>>);
}

// 2. Доступ к элементам

TEST(MatrixTest, ElementAccess)
{
    Matrix<int> matrix(2, 2);
    matrix(0, 1) = 5;
    matrix.at(1, 0) = 6;
    const Matrix<int>& view = matrix;
    EXPECT_EQ(view(0, 1), 5);
    EXPECT_EQ(view.at(1, 0), 6);
}

TEST(MatrixTest, AtChecksIndices)
{
    Matrix<int> matrix(2, 3);
    EXPECT_THROW(static_cast<void>(matrix.at(2, 0)), std::out_of_range);
    EXPECT_THROW(static_cast<void>(matrix.at(0, 3)), std::out_of_range);
    const Matrix<int>& view = matrix;
    EXPECT_THROW(static_cast<void>(view.at(2, 0)), std::out_of_range);
}

// 3. Операции

TEST(MatrixTest, AddAndSubtract)
{
    const Matrix<int> a{{1, 2}, {3, 4}};
    const Matrix<int> b{{4, 3}, {2, 1}};
    EXPECT_EQ(toString(a + b), "5 5\n5 5\n");
    EXPECT_EQ(toString(a - b), "-3 -1\n1 3\n");
    Matrix<int> c = a;
    c += b;
    c -= a;
    EXPECT_EQ(c, b);
}

TEST(MatrixTest, DifferentSizesThrow)
{
    const Matrix<int> a(2, 2);
    const Matrix<int> b(2, 3);
    EXPECT_THROW(a + b, std::invalid_argument);
    EXPECT_THROW(a - b, std::invalid_argument);
}

TEST(MatrixTest, MultiplyAndDivideByValue)
{
    const Matrix<int> a{{1, 2}, {3, 4}};
    EXPECT_EQ(toString(a * 2), "2 4\n6 8\n");
    EXPECT_EQ(toString(2 * a), "2 4\n6 8\n");
    EXPECT_EQ(toString((a * 2) / 2), "1 2\n3 4\n");
    Matrix<int> b = a;
    b *= 3;
    b /= 3;
    EXPECT_EQ(b, a);
}

TEST(MatrixTest, DivisionByZeroThrows)
{
    Matrix<int> a(1, 1, 5);
    EXPECT_THROW(a / 0, std::domain_error);
    EXPECT_THROW(a /= 0, std::domain_error);
}

TEST(MatrixTest, MatrixProduct)
{
    const Matrix<int> a{{1, 2}, {3, 4}};
    const Matrix<int> b{{5}, {6}};
    EXPECT_EQ(toString(a * b), "17\n39\n");
    EXPECT_EQ(a * Matrix<int>::identity(2), a);
}

TEST(MatrixTest, ProductOfMismatchedSizesThrows)
{
    EXPECT_THROW(Matrix<int>(2, 3) * Matrix<int>(2, 3), std::invalid_argument);
}

TEST(MatrixTest, UnaryMinus)
{
    EXPECT_EQ(toString(-Matrix<int>{{1, -2}}), "-1 2\n");
}

TEST(MatrixTest, Equality)
{
    EXPECT_TRUE((Matrix<int>{{1, 2}} == Matrix<int>{{1, 2}}));
    EXPECT_TRUE((Matrix<int>{{1, 2}} != Matrix<int>{{1, 3}}));
    EXPECT_TRUE((Matrix<int>{{1, 2}} != Matrix<int>{{1}, {2}}));
    EXPECT_TRUE((Matrix<int>{} == Matrix<int>{}));
}

// 4. Ввод и вывод

TEST(MatrixTest, Input)
{
    std::istringstream in{"2 2 1 2 3 4"};
    Matrix<int> matrix;
    in >> matrix;
    EXPECT_FALSE(in.fail());
    EXPECT_EQ(toString(matrix), "1 2\n3 4\n");
}

TEST(MatrixTest, InputErrorKeepsMatrix)
{
    std::istringstream in{"2 2 1 2 x 4"};
    Matrix<int> matrix{{9}};
    in >> matrix;
    EXPECT_TRUE(in.fail());
    EXPECT_EQ(toString(matrix), "9\n");
}
