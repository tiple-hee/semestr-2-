#include <iostream>
#include <string>
#include <cstdlib>
#include "PriorityQueue.h"
using namespace std;

enum Actions
{INSERT = 1, REMOVE_MAX, SEARCH_MAX};

void ERROR(const string text)
{
    cerr << text << endl;
    exit(1);
}

int get_choice()
{
    int number = 0;
    cin >> number;
    if (cin.fail())
    {
        ERROR("Ошибка ввода");
    }
    return number;
}

int main()
{
    PriorityQueue collection;
    
    cout << "Укажите начальное количество элементов очереди: ";
    int n = get_choice();
    if (n < 0)
    {
        ERROR("Ошибка: количество элементов не может быть отрицательным.");
    }
    
    if (n > 0)
    {
        cout << "Введите " << n << " элементов (чем больше число, тем выше его приоритет): " << endl;
        for (size_t i = 0; i < static_cast<size_t>(n); ++i)
        {
            int val = get_choice();
            collection.insert(val);
        }
    }
    
    cout << "Изначальная очередь (сортируется автоматически по приоритету): " << collection << endl;
    cout << "Выберите действие: " << endl
         << INSERT << " - Вставить элемент" << endl
         << REMOVE_MAX << " - Удалить элемент с наибольшим приоритетом" << endl
         << SEARCH_MAX << " - Найти элемент с наибольшим приоритетом" << endl;
         
    cout << "Ваш выбор: ";
    int choice = get_choice();
    
    try
    {
        switch (choice)
        {
        case INSERT:
        {
            cout << "Введите значение для вставки: ";
            int val = get_choice();
            collection.insert(val);
            cout << "После добавления: " << collection << endl;
            break;
        }
        case REMOVE_MAX:
        {
            collection.removeMax();
            cout << "После удаления элемента с наибольшим приоритетом: " << collection << endl;
            break;
        }
        case SEARCH_MAX:
        {
            int max_val = collection.getMax();
            cout << "Элемент с наибольшим приоритетом равен: " << max_val << endl;
            break;
        }
        default:
            ERROR("Ошибка: Неверный выбор пункта меню.");
        }
    }
    catch (const exception &e)
    {
        cout << "Ошибка! " << e.what() << endl;
    }
    
    if (!collection.is_empty())
    {
        cout << endl
             << "Текущий элемент с наивысшим приоритетом: " << collection.getMax() << endl;
    }
    
    return 0;
}
