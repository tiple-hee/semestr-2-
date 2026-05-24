/**
 * @file main.cpp
 * @brief Точка входа в программу. Демонстрация работы классов Piquet и Peregon.
 */

#include <iostream>
#include "Piquet.h"
#include "Peregon.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "--- Демонстрация работы с Пикетами ---\n";
    Piquet p1(0, 0.0, 100.0);
    Piquet p2(10, 50.0, 100.0);
    
    std::cout << "Точка А: " << p1 << "\n";
    std::cout << "Точка Б: " << p2 << "\n";
    std::cout << "Расстояние: " << p1.distanceTo(&p2) << " м\n\n";

    std::cout << "--- Демонстрация работы с Перегоном ---\n";
    Peregon peregon(p1, p2);
    Piquet badPiquet1(3, 0.0, 80.0); 
    Piquet badPiquet2(7, 0.0, 120.0); 

    peregon.addPiquet(badPiquet1);
    peregon.addPiquet(badPiquet2);

    std::cout << peregon;
    std::cout << "Итоговая расчетная длина перегона: " << peregon.calculateLength() << " м\n";
    std::cout << "\n--- Проверка ручного ввода ---";
    Peregon customPeregon(0, 0); 
    std::cin >> customPeregon;
    std::cout << "\nВы ввели:\n" << customPeregon;
    std::cout << "Длина вашего перегона: " << customPeregon.calculateLength() << " м\n";

    return 0;
}