#include "Peregon.h"

Peregon::Peregon(const Piquet& start, const Piquet& end)
{
    if (start < end) {
        startPoint = start;
        endPoint = end;
    } else {
        startPoint = end;
        endPoint = start;
    }
}

Peregon::Peregon(const double startMeters, const double endMeters)
{
    Piquet p1(startMeters);
    Piquet p2(endMeters);
    if (p1 < p2) {
        startPoint = p1;
        endPoint = p2;
    } else {
        startPoint = p2;
        endPoint = p1;
    }
}

void Peregon::addPiquet(const Piquet p)
{
    if (!p.isStandard) {
        badPiquets.push_back(p);
        for (size_t i = 0; i < badPiquets.size(); i++) {
            for (size_t j = i + 1; j < badPiquets.size(); j++) {
                if (badPiquets[j] < badPiquets[i]) {
                    Piquet temp = badPiquets[i];
                    badPiquets[i] = badPiquets[j];
                    badPiquets[j] = temp;
                }
            }
        }
    }
}

double Peregon::calculateLength() const
{
    double baseLength = endPoint.getAbsolutePosition() - startPoint.getAbsolutePosition();
    double difference = 0.0;

    for (size_t i = 0; i < badPiquets.size(); i++) {
        if (startPoint < badPiquets[i] && badPiquets[i] < endPoint) {
            difference += (100.0 - badPiquets[i].length);
        }
    }
    return baseLength - difference;
}

std::string Peregon::toString() const
{
    std::string res = "Перегон от " + startPoint.toString() + " до " + endPoint.toString() + "\n";
    res += "Немерных пикетов на участке: " + std::to_string(badPiquets.size()) + "\n";
    for (size_t i = 0; i < badPiquets.size(); i++) {
        res += " - " + badPiquets[i].toString() + " (длина: " + std::to_string(badPiquets[i].length) + " м)\n";
    }
    return res;
}

std::ostream& operator<<(std::ostream& os, const Peregon& p)
{
    os << p.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Peregon& p)
{
    std::cout << "\nВведите начальный пикет (Номер Смещение Длина через пробел): ";
    is >> p.startPoint;
    std::cout << "Введите конечный пикет (Номер Смещение Длина через пробел): ";
    is >> p.endPoint;
    
    if (p.endPoint < p.startPoint) {
        Piquet temp = p.startPoint;
        p.startPoint = p.endPoint;
        p.endPoint = temp;
    }
    return is;
}
