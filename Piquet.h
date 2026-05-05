#pragma once
#include "PointDistance.h"
#include <string>
#include <iostream>

/**
 * @brief Класс Пикет (единица измерения расстояния на железной дороге).
 * * Пикет представляет собой точку на трассе, состоящую из целого номера и 
 * дробного смещения. Стандартная длина пикета — 100 метров.
 */
class Piquet : public PointDistance
{
public:
    int number;       
    double shift;    
    double length;  
    bool isStandard;  

    /**
     * @brief Конструктор по умолчанию. 
     * Создает нулевой пикет (ПК 0+0.0) стандартной длины.
     */
    Piquet();

    /**
     * @brief Конструктор, принимающий расстояние в метрах (вещественный тип).
     * Автоматически переводит метры в номер пикета и смещение.
     * * @param meters Расстояние от начала координат в метрах.
     */
    Piquet(const double meters);

    /**
     * @brief Конструктор с полным набором параметров.
     * * @param num Номер пикета.
     * @param sh Смещение (в метрах).
     * @param len Длина пикета (по умолчанию для проверки стандарта).
     */
    Piquet(const int num,const double sh,const double len);

    /**
     * @brief Получить абсолютную координату точки в метрах.
     * Используется для внутренних расчетов расстояний.
     * * @return double Координата в метрах.
     */
    double getAbsolutePosition() const;

    /**
     * @brief Реализация абстрактного метода: расчет расстояния до другой точки.
     * * @param other Указатель на другую точку.
     * @return double Расстояние в метрах (абсолютное значение).
     */
    double distanceTo(const PointDistance* other) const override;

    /**
     * @brief Формирует строковое представление пикета.
     * * Формат: "ПК Номер+Смещение" (или "ПК 0Номер+Смещение" для отрицательных).
     * @return std::string Строка с описанием пикета.
     */
    std::string toString() const;

    bool operator==(const Piquet& other) const;
    bool operator!=(const Piquet& other) const;
    bool operator<(const Piquet& other) const;
    bool operator>(const Piquet& other) const;

    /**
     * @brief Оператор вывода в стандартный поток.
     */
    friend std::ostream& operator<<(std::ostream& os, const Piquet& p);

    /**
     * @brief Оператор ввода из стандартного потока.
     */
    friend std::istream& operator>>(std::istream& is, Piquet& p);
};
