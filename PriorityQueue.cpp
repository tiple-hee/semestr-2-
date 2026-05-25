#include <iostream>
#include "PriorityQueue.h"
#include <sstream>
#include <stdexcept>

PriorityQueue::PriorityQueue() : m_elements(nullptr), m_count(0) {}

PriorityQueue::PriorityQueue(const std::initializer_list<int> items) : m_elements(nullptr), m_count(0)
{
    for (const int &val : items)
    {
        insert(val);
    }
}

PriorityQueue::~PriorityQueue()
{
    delete[] m_elements;
}

PriorityQueue::PriorityQueue(const PriorityQueue &other) : m_elements(nullptr), m_count(other.m_count)
{
    if (m_count > 0)
    {
        m_elements = new int[m_count];
        for (size_t i = 0; i < m_count; ++i)
        {
            m_elements[i] = other.m_elements[i];
        }
    }
}

PriorityQueue::PriorityQueue(PriorityQueue &&other) : m_elements(other.m_elements), m_count(other.m_count)
{
    other.m_elements = nullptr;
    other.m_count = 0;
}

std::string PriorityQueue::to_string() const
{
    if (is_empty())
        return "Empty";

    std::stringstream ss;
    for (size_t i = 0; i < m_count; ++i)
    {
        ss << m_elements[i];
        if (i < m_count - 1)
            ss << " ";
    }
    return ss.str();
}

size_t PriorityQueue::get_size() const
{
    return m_count;
}

bool PriorityQueue::is_empty() const
{
    return m_count == 0;
}

void PriorityQueue::insert(const int value)
{
    int *tempArray = new int[m_count + 1];
    
    size_t insertIndex = 0;
    while (insertIndex < m_count && m_elements[insertIndex] >= value)
    {
        insertIndex++;
    }

    for (size_t i = 0; i < insertIndex; ++i)
    {
        tempArray[i] = m_elements[i];
    }
    
    tempArray[insertIndex] = value;
    
    for (size_t i = insertIndex; i < m_count; ++i)
    {
        tempArray[i + 1] = m_elements[i];
    }

    delete[] m_elements;
    m_elements = tempArray;
    m_count++;
}

void PriorityQueue::removeMax()
{
    if (is_empty())
    {
        throw std::out_of_range("Очередь пуста!");
    }
    
    int *tempArray = (m_count > 1) ? new int[m_count - 1] : nullptr;
    
    for (size_t i = 1; i < m_count; ++i)
    {
        tempArray[i - 1] = m_elements[i];
    }
    
    delete[] m_elements;
    m_elements = tempArray;
    m_count--;
}

int PriorityQueue::getMax() const
{
    if (is_empty())
    {
        throw std::out_of_range("Очередь пуста!");
    }
    return m_elements[0];
}

PriorityQueue &PriorityQueue::operator=(const PriorityQueue &other)
{
    if (this != &other)
    {
        delete[] m_elements;
        m_count = other.m_count;
        m_elements = (m_count > 0) ? new int[m_count] : nullptr;
        for (size_t i = 0; i < m_count; ++i)
        {
            m_elements[i] = other.m_elements[i];
        }
    }
    return *this;
}

PriorityQueue &PriorityQueue::operator=(PriorityQueue &&other)
{
    if (this != &other)
    {
        delete[] m_elements;
        m_elements = other.m_elements;
        m_count = other.m_count;
        other.m_elements = nullptr;
        other.m_count = 0;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const PriorityQueue &pq)
{
    os << pq.to_string();
    return os;
}

std::istream &operator>>(std::istream &is, PriorityQueue &pq)
{
    int value = 0;
    if (is >> value)
    {
        pq.insert(value);
    }
    return is;
}
