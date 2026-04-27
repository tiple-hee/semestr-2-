#include "Piquet.h"
#include <cmath>
#include <sstream>

Piquet::Piquet() : number(0), shift(0.0), length(100.0), isStandard(true) {}

Piquet::Piquet(double meters)
{
    number = (int)(meters / 100);
    shift = meters - number * 100;
    if (shift < 0) {
        number -= 1;
        shift += 100;
    }
    length = 100.0;
    isStandard = true;
}

Piquet::Piquet(int num, double sh, double len)
{
    number = num;
    shift = sh;
    length = len;
    isStandard = (len == 100.0);
}

double Piquet::getAbsolutePosition() const
{
    return number * 100.0 + shift;
}

double Piquet::distanceTo(const PointDistance* other) const
{
    const Piquet* otherPiquet = dynamic_cast<const Piquet*>(other);
    if (otherPiquet) {
        return std::abs(this->getAbsolutePosition() - otherPiquet->getAbsolutePosition());
    }
    return 0.0;
}

std::string Piquet::toString() const
{
    std::ostringstream oss;
    oss << "ПК ";
    if (number < 0) {
        oss << "0" << std::abs(number); 
    } else {
        oss << number;
    }
    oss << "+" << shift;
    return oss.str();
}

bool Piquet::operator==(const Piquet& other) const {
    return this->getAbsolutePosition() == other.getAbsolutePosition();
}
bool Piquet::operator!=(const Piquet& other) const {
    return !(*this == other);
}
bool Piquet::operator<(const Piquet& other) const {
    return this->getAbsolutePosition() < other.getAbsolutePosition();
}
bool Piquet::operator>(const Piquet& other) const {
    return this->getAbsolutePosition() > other.getAbsolutePosition();
}

std::ostream& operator<<(std::ostream& os, const Piquet& p)
{
    os << p.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Piquet& p)
{
    is >> p.number >> p.shift >> p.length;
    p.isStandard = (p.length == 100.0);
    return is;
}