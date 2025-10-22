#pragma once

#include <iostream>
#include <cmath>

// Структура для представления точки на плоскости
struct Point
{
    double x;
    double y;

    Point() : x(0.0), y(0.0) {}
    Point(double x, double y) : x(x), y(y) {}

    // Оператор сравнения точек
    bool operator==(const Point &other) const
    {
        return std::abs(x - other.x) < 1e-9 && std::abs(y - other.y) < 1e-9;
    }

    // Расстояние между точками
    double distanceTo(const Point &other) const
    {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

// Перегрузка оператора вывода для Point
inline std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

// Перегрузка оператора ввода для Point
inline std::istream &operator>>(std::istream &is, Point &p)
{
    is >> p.x >> p.y;
    return is;
}
