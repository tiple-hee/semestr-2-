#include <iostream>
#include <string>
#include "tetrahedron.h"
#include "point.h"

/**
 * @brief Считывает значение, введенное с клавиатуры, с защитой от ошибок
 */
double getValue(std::string report = "");

/**
 * @brief Считывает координаты X, Y, Z и возвращает готовую точку
 */
Point getPoint();

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "--- Расчет площади основания тетраэдра (3D координаты) ---" << std::endl;
    
    std::cout << "1-я точка:\n";
    Point p1 = getPoint();

    std::cout << "2-я точка:\n";
    Point p2 = getPoint();

    std::cout << "3-я точка:\n";
    Point p3 = getPoint();

    std::cout << "4-я точка (необходима для формирования корректного 3D-тетраэдра):\n";
    Point p4 = getPoint();

    // Создаем объект (проверяет точки на совпадение и вырожденность)
    Tetrahedron myTetra(p1, p2, p3, p4);

    // Вывод результата
    std::cout << "\nРезультат:" << std::endl;
    std::cout << "Площадь основания тетраэдра равна: " << myTetra.getBaseArea() << std::endl;

    return 0;
}

double getValue(std::string report)
{
    std::cout << report;
    double value = 0;
    std::cin >> value;
    
    if (std::cin.fail())
    {
        std::cout << "Ошибка, введено неверное значение!\n";
        exit(1);
    }
    return value;
}

Point getPoint()
{
    double x = getValue("X: "); 
    double y = getValue("Y: "); 
    double z = getValue("Z: ");
    return Point(x, y, z);
}
