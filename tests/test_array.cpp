#include <gtest/gtest.h>
#include "FigureArray.h"
#include "Triangle.h"
#include "Square.h"
#include "Octagon.h"

// Тесты для класса FigureArray

TEST(FigureArrayTest, DefaultConstructor)
{
    FigureArray array;
    EXPECT_EQ(array.getSize(), 0);
}

TEST(FigureArrayTest, AddFigure)
{
    FigureArray array;

    Triangle *triangle = new Triangle();
    array.add(triangle);

    EXPECT_EQ(array.getSize(), 1);
}

TEST(FigureArrayTest, AddMultipleFigures)
{
    FigureArray array;

    array.add(new Triangle());
    array.add(new Square());
    array.add(new Octagon());

    EXPECT_EQ(array.getSize(), 3);
}

TEST(FigureArrayTest, RemoveFigure)
{
    FigureArray array;

    array.add(new Triangle());
    array.add(new Square());
    array.add(new Octagon());

    array.remove(1);

    EXPECT_EQ(array.getSize(), 2);
}

TEST(FigureArrayTest, RemoveInvalidIndex)
{
    FigureArray array;
    array.add(new Triangle());

    EXPECT_THROW(array.remove(5), std::out_of_range);
}

TEST(FigureArrayTest, GetFigure)
{
    FigureArray array;

    Triangle *triangle = new Triangle();
    double area = triangle->getArea();
    array.add(triangle);

    const Figure *fig = array.get(0);
    EXPECT_DOUBLE_EQ(fig->getArea(), area);
}

TEST(FigureArrayTest, GetInvalidIndex)
{
    FigureArray array;

    EXPECT_THROW(array.get(0), std::out_of_range);
}

TEST(FigureArrayTest, GetTotalArea)
{
    FigureArray array;

    Point p1(0, 0), p2(2, 0), p3(2, 2), p4(0, 2);
    Square *square = new Square(p1, p2, p3, p4);
    double squareArea = square->getArea();

    Point t1(0, 0), t2(4, 0), t3(0, 3);
    Triangle *triangle = new Triangle(t1, t2, t3);
    double triangleArea = triangle->getArea();

    array.add(square);
    array.add(triangle);

    EXPECT_DOUBLE_EQ(array.getTotalArea(), squareArea + triangleArea);
}

TEST(FigureArrayTest, IndexOperator)
{
    FigureArray array;

    array.add(new Triangle());

    const Figure *fig = array[0];
    EXPECT_NE(fig, nullptr);
}

TEST(FigureArrayTest, CopyConstructor)
{
    FigureArray array1;

    array1.add(new Triangle());
    array1.add(new Square());

    FigureArray array2(array1);

    EXPECT_EQ(array1.getSize(), array2.getSize());
    EXPECT_DOUBLE_EQ(array1.getTotalArea(), array2.getTotalArea());
}

TEST(FigureArrayTest, MoveConstructor)
{
    FigureArray array1;

    array1.add(new Triangle());
    array1.add(new Square());

    size_t size = array1.getSize();
    double area = array1.getTotalArea();

    FigureArray array2(std::move(array1));

    EXPECT_EQ(array2.getSize(), size);
    EXPECT_DOUBLE_EQ(array2.getTotalArea(), area);
    EXPECT_EQ(array1.getSize(), 0);
}

TEST(FigureArrayTest, CopyAssignment)
{
    FigureArray array1;
    FigureArray array2;

    array1.add(new Triangle());
    array1.add(new Square());

    array2 = array1;

    EXPECT_EQ(array1.getSize(), array2.getSize());
    EXPECT_DOUBLE_EQ(array1.getTotalArea(), array2.getTotalArea());
}

TEST(FigureArrayTest, MoveAssignment)
{
    FigureArray array1;
    FigureArray array2;

    array1.add(new Triangle());
    array1.add(new Square());

    size_t size = array1.getSize();
    double area = array1.getTotalArea();

    array2 = std::move(array1);

    EXPECT_EQ(array2.getSize(), size);
    EXPECT_DOUBLE_EQ(array2.getTotalArea(), area);
    EXPECT_EQ(array1.getSize(), 0);
}
