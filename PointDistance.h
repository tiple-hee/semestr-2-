#pragma once

/**
 * @brief Абстрактный базовый класс Расчета расстояния между двумя точками.
 * * Служит интерфейсом для всех классов, представляющих точки на координатной 
 * прямой или плоскости, между которыми можно вычислить расстояние.
 */
class PointDistance
{
public:
    /**
     * @brief Виртуальный деструктор по умолчанию.
     */
    virtual ~PointDistance() = default;

    /**
     * @brief Абстрактный метод расчета расстояния до другой точки.
     * * @param other Указатель на другой объект точки (наследник PointDistance).
     * @return double Расстояние между текущей точкой и точкой other.
     */
    virtual double distanceTo(const PointDistance* other) const = 0;
};