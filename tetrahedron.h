#pragma once
#include "point.h"

/**
 * @brief Класс Тетраэдр
 */
class Tetrahedron
{
private:
    Point p1;
    Point p2;
    Point p3;
    Point p4;

public:
    /**
     * @brief Конструктор тетраэдра
     */
    Tetrahedron(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

    /**
     * @brief Расчет площади основания тетраэдра (по первым трем точкам p1, p2, p3)
     * @return значение площади (double)
     */
    double getBaseArea() const;

    /**
     * @brief Расчет объема тетраэдра
     * @return значение объема (double)
     */
    double getVolume() const;
};