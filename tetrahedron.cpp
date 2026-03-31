#include "tetrahedron.h"
#include <iostream>
#include <cmath>

Tetrahedron::Tetrahedron(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->p4 = p4;
    
    if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4)
    {
        std::cout << "Ошибка: Некоторые точки совпадают! Тетраэдр задать невозможно." << std::endl;
        exit(1);
    }

    // Векторы, исходящие из p1
    double ax = p2.getX() - p1.getX(), ay = p2.getY() - p1.getY(), az = p2.getZ() - p1.getZ();
    double bx = p3.getX() - p1.getX(), by = p3.getY() - p1.getY(), bz = p3.getZ() - p1.getZ();
    double cx = p4.getX() - p1.getX(), cy = p4.getY() - p1.getY(), cz = p4.getZ() - p1.getZ();
    
    // Смешанное произведение (определитель)
    double det = ax * (by * cz - bz * cy) - ay * (bx * cz - bz * cx) + az * (bx * cy - by * cx);
    
    // Защита от вырожденного (плоского) тетраэдра
    // Используем небольшую погрешность (epsilon) из-за особенностей арифметики double
    if (std::abs(det) < 1e-9) 
    {
        std::cout << "Ошибка: Точки лежат в одной плоскости! Объем равен нулю." << std::endl;
        exit(1);
    }
}

double Tetrahedron::getBaseArea() const
{
    double ax = p2.getX() - p1.getX(), ay = p2.getY() - p1.getY(), az = p2.getZ() - p1.getZ();
    double bx = p3.getX() - p1.getX(), by = p3.getY() - p1.getY(), bz = p3.getZ() - p1.getZ();
    
    double nx = ay * bz - az * by;
    double ny = az * bx - ax * bz;
    double nz = ax * by - ay * bx;
    
    return 0.5 * std::sqrt(nx * nx + ny * ny + nz * nz);
}

double Tetrahedron::getVolume() const
{
    // Аналогичный расчет смешанного произведения для получения объема
    double ax = p2.getX() - p1.getX(), ay = p2.getY() - p1.getY(), az = p2.getZ() - p1.getZ();
    double bx = p3.getX() - p1.getX(), by = p3.getY() - p1.getY(), bz = p3.getZ() - p1.getZ();
    double cx = p4.getX() - p1.getX(), cy = p4.getY() - p1.getY(), cz = p4.getZ() - p1.getZ();
    
    double det = ax * (by * cz - bz * cy) - ay * (bx * cz - bz * cx) + az * (bx * cy - by * cx);
    
    return std::abs(det) / 6.0;
}