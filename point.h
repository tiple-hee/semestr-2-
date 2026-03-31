#pragma once

/**
 * @brief Класс Точка для работы в 3D пространстве
 */
class Point
{
private:
    double x;
    double y;
    double z;

public:
    Point(double x = 0, double y = 0, double z = 0);

    double getX() const;
    double getY() const;
    double getZ() const;

    /**
     * @brief Проверка на неравенство точек
     */
    bool operator!=(const Point& p) const;
};
