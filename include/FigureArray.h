#pragma once

#include "Figure.h"
#include <stdexcept>

// Динамический массив для хранения указателей на фигуры
class FigureArray
{
private:
    Figure **data;   // Массив указателей на фигуры
    size_t capacity; // Емкость массива
    size_t size;     // Текущее количество элементов

    // Увеличение емкости массива
    void resize();

public:
    // Конструктор по умолчанию
    FigureArray();

    // Конструктор с начальной емкостью
    explicit FigureArray(size_t initialCapacity);

    // Копирующий конструктор
    FigureArray(const FigureArray &other);

    // Перемещающий конструктор
    FigureArray(FigureArray &&other) noexcept;

    // Оператор копирующего присваивания
    FigureArray &operator=(const FigureArray &other);

    // Оператор перемещающего присваивания
    FigureArray &operator=(FigureArray &&other) noexcept;

    // Деструктор
    ~FigureArray();

    // Добавление фигуры в массив
    void add(Figure *figure);

    // Удаление фигуры по индексу
    void remove(size_t index);

    // Получение фигуры по индексу (константная версия)
    const Figure *get(size_t index) const;

    // Получение фигуры по индексу (неконстантная версия)
    Figure *get(size_t index);

    // Получение текущего размера массива
    size_t getSize() const;

    // Вычисление общей площади всех фигур
    double getTotalArea() const;

    // Печать всех фигур
    void printAll(std::ostream &os) const;

    // Печать информации о центрах и площадях
    void printCentersAndAreas(std::ostream &os) const;

    // Оператор индексации (константная версия)
    const Figure *operator[](size_t index) const;

    // Оператор индексации (неконстантная версия)
    Figure *operator[](size_t index);
};
