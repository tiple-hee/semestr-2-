#include "point.h"
#include <cmath> // Необходимо для функции std::abs

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point::getX() const { return this->x; }
double Point::getY() const { return this->y; }
double Point::getZ() const { return this->z; }

bool Point::operator!=(const Point& p) const
{
    const double epsilon = 1e-9;
    return (std::abs(this->x - p.x) > epsilon || 
            std::abs(this->y - p.y) > epsilon || 
            std::abs(this->z - p.z) > epsilon);
}
