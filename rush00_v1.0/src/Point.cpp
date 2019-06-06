#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y): x(x), y(y) {}

Point::Point(const Point &other) {
    *this = other;
}

Point& Point::operator=(const Point &other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
}

Point::~Point() {}

int Point::getX() const {
    return x;
}

void Point::setX(int x) {
    Point::x = x;
}

int Point::getY() const {
    return y;
}

void Point::setY(int y) {
    Point::y = y;
}

void Point::addX(int value) {
    x += value;
}

void Point::addY(int value) {
    y += value;
}

Point Point::operator+(const Point &other) {
    Point newPoint = Point(*this);
    newPoint.x += other.x;
    newPoint.y += other.y;
    return newPoint;
}

Point Point::operator-(const Point &other) {
    Point newPoint = Point(*this);
    newPoint.x -= other.x;
    newPoint.y -= other.y;
    return newPoint;
}

bool Point::operator==(const Point &other) {
    return (x == other.x && y == other.y);
}

bool Point::operator!=(const Point &other) {
    return (x != other.x || y != other.y);
}