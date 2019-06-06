#include "Metheorite.hpp"

Metheorite::Metheorite() : name("meteor") {}

Metheorite::Metheorite(const Metheorite &other) {
    *this = other;
}

Metheorite::Metheorite(const Point &point) : name("meteor"), point(point) {}

Metheorite& Metheorite::operator=(const Metheorite &other) {
    name = other.name;
    point = other.point;
    return *this;
}

const std::string &Metheorite::getName() const {
    return this->name;
}

Point Metheorite::getPoint() const {
    return point;
}

void Metheorite::move(const Point& shift) {
    point = point + shift;
}

Metheorite::~Metheorite() {}

bool Metheorite::isDead() const {
    return dead;
}

void Metheorite::setDead(bool value) {
    dead = value;
}

void Metheorite::setNewPosition(Point newPoint) {
    point = newPoint;
}