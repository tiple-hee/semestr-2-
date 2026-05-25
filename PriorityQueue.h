#pragma once
#include <iostream>
#include <initializer_list>
#include <string>

/**
 * @brief Класс Очередь с приоритетом (на основе массива целых чисел)
 * Элементы хранятся по убыванию, где значение = приоритет.
 */
class PriorityQueue
{
private:
    /**
     * @brief Указатель на массив элементов
     */
    int *m_elements;

    /**
     * @brief Количество элементов в коллекции
     */
    size_t m_count;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    PriorityQueue();
    
    /**
     * @brief Конструктор со списком инициализации
     */
    PriorityQueue(const std::initializer_list<int> items);
    
    /**
     * @brief Конструктор копирования
     */
    PriorityQueue(const PriorityQueue &other);
    
    /**
     * @brief Конструктор перемещения
     */
    PriorityQueue(PriorityQueue &&other);
    
    /**
     * @brief Деструктор
     */
    ~PriorityQueue();
    
    /**
     * @brief Возвращает строку с содержимым коллекции
     */
    std::string to_string() const;
    
    /**
     * @brief Возвращает текущий размер
     */
    size_t get_size() const;
    
    /**
     * @brief Проверка коллекции на пустоту
     */
    bool is_empty() const;
    
    /**
     * @brief Вставка элемента в очередь с учетом приоритета
     * @param value новое значение (оно же приоритет)
     */
    void insert(const int value);
    
    /**
     * @brief Удаление элемента с наибольшим приоритетом
     */
    void removeMax();
    
    /**
     * @brief Поиск элемента с наибольшим приоритетом
     * @return значение с наибольшим приоритетом
     */
    int getMax() const;
    
    /**
     * @brief Оператор присваивания (копирование)
     */
    PriorityQueue &operator=(const PriorityQueue &other);
    
    /**
     * @brief Оператор присваивания (перемещение)
     */
    PriorityQueue &operator=(PriorityQueue &&other);
    
    /**
     * @brief Перегрузка оператора сдвига влево
     */
    friend std::ostream &operator<<(std::ostream &os, const PriorityQueue &pq);
    
    /**
     * @brief Перегрузка оператора сдвига вправо
     */
    friend std::istream &operator>>(std::istream &is, PriorityQueue &pq);
};
