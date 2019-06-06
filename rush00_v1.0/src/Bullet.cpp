#include "Bullet.hpp"

Bullet::Bullet() {}

Bullet::Bullet(const Bullet &other) {
    *this = other;
}

Bullet::Bullet(const Point &point, std::string name) : name(name), point(point) {}

Bullet& Bullet::operator=(const Bullet &other) {
    name = other.name;
    point = other.point;
    return *this;
}

const std::string &Bullet::getName() const {
    return name;
}

Point Bullet::getPoint() const {
    return point;
}

void Bullet::move(const Point& shift) {
    point = point + shift;
}

Bullet::~Bullet() {}

bool Bullet::isDead() const {
    return dead;
}

void Bullet::setDead(bool value) {
    dead = value;
}

void Bullet::setNewPosition(Point newPoint) {
    point = newPoint;
}