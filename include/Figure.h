#pragma once

#include <iostream>
#include "Point.h"

// Абстрактный базовый класс для всех фигур
class Figure
{
public:
    // Виртуальный деструктор
    virtual ~Figure() = default;

    // Чистая виртуальная функция для вычисления геометрического центра
    virtual Point getCenter() const = 0;

    // Чистая виртуальная функция для вычисления площади
    virtual double getArea() const = 0;

    // Чистая виртуальная функция для вывода координат вершин
    virtual void print(std::ostream &os) const = 0;

    // Чистая виртуальная функция для чтения координат из потока
    virtual void read(std::istream &is) = 0;

    // Чистая виртуальная функция для клонирования объекта
    virtual Figure *clone() const = 0;

    // Чистая виртуальная функция для сравнения фигур
    virtual bool equals(const Figure &other) const = 0;

    // Оператор приведения к типу double (возвращает площадь)
    explicit operator double() const
    {
        return getArea();
    }

    // Виртуальная функция для получения имени типа фигуры
    virtual const char *getTypeName() const = 0;
};

// Перегрузка оператора вывода для Figure
inline std::ostream &operator<<(std::ostream &os, const Figure &figure)
{
    figure.print(os);
    return os;
}

// Перегрузка оператора ввода для Figure
inline std::istream &operator>>(std::istream &is, Figure &figure)
{
    figure.read(is);
    return is;
}
