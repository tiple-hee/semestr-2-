#pragma once
#include "Piquet.h"
#include <vector>
#include <string>

/**
 * @brief Класс Перегон.
 * * Представляет собой участок пути между двумя точками (пикетами).
 * Может содержать внутри себя "немерные" (нестандартные) пикеты, 
 * которые влияют на общую длину перегона.
 */
class Peregon
{
public:
    Piquet startPoint;                 
    Piquet endPoint;                  
    std::vector<Piquet> badPiquets;   

    /**
     * @brief Конструктор от двух существующих пикетов.
     * * @param start Начальный пикет.
     * @param end Конечный пикет.
     */
    Peregon(Piquet start, Piquet end);

    /**
     * @brief Конструктор от двух вещественных значений (координаты в метрах).
     * * @param startMeters Начальная координата.
     * @param endMeters Конечная координата.
     */
    Peregon(double startMeters, double endMeters);

    /**
     * @brief Добавление нового немерного пикета на перегон.
     * Пикет добавляется в вектор и сортируется по положению (пикетажу).
     * * @param p Объект пикета.
     */
    void addPiquet(Piquet p);

    /**
     * @brief Расчет фактической длины перегона с учетом немерных пикетов.
     * * @return double Длина перегона в метрах.
     */
    double calculateLength() const;

    /**
     * @brief Сериализация информации о перегоне в строку.
     * * @return std::string Детальное описание перегона и списка его немерных пикетов.
     */
    std::string toString() const;

    /**
     * @brief Оператор вывода перегона в стандартный поток.
     */
    friend std::ostream& operator<<(std::ostream& os, const Peregon& p);

    /**
     * @brief Оператор ввода параметров перегона с клавиатуры.
     */
    friend std::istream& operator>>(std::istream& is, Peregon& p);
};