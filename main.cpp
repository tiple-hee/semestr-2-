#include <iostream>
#include <string>
#include "tetrahedron.h"
#include "point.h"

/**
 * @brief Считывает значение, введенное с клавиатуры, с защитой от ошибок
 * @param report - текст подсказки для вывода в консоль
 * @return считанное значение типа double
 */
double getValue(std::string report = "");

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "--- Расчет площади основания тетраэдра (3D координаты) ---" << std::endl;
    
    // Ввод 1-й точки
    double x1 = getValue("1 точка X: "); double y1 = getValue("1 точка Y: "); double z1 = getValue("1 точка Z: ");
    Point p1(x1, y1, z1);

    // Ввод 2-й точки
    double x2 = getValue("2 точка X: "); double y2 = getValue("2 точка Y: "); double z2 = getValue("2 точка Z: ");
    Point p2(x2, y2, z2);

    // Ввод 3-й точки
    double x3 = getValue("3 точка X: "); double y3 = getValue("3 точка Y: "); double z3 = getValue("3 точка Z: ");
    Point p3(x3, y3, z3);

    // Ввод 4-й точки (необходима для формирования корректного 3D-тетраэдра)
    double x4 = getValue("4 точка X: "); double y4 = getValue("4 точка Y: "); double z4 = getValue("4 точка Z: ");
    Point p4(x4, y4, z4);

    // Создаем объект (проверяет точки на совпадение и вырожденность)
    Tetrahedron myTetra(p1, p2, p3, p4);

    // Вывод результата
    std::cout << "\nРезультат:" << std::endl;
    // Вызываем нужный метод для расчета площади основания (по p1, p2, p3)
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