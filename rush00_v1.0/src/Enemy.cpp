#include "Enemy.hpp"

Enemy::Enemy() : name("player") {}

Enemy::Enemy(const Enemy &other) {
    *this = other;
}

Enemy::Enemy(const Point &point) : name("enemy"), point(point) {}

Enemy& Enemy::operator=(const Enemy &other) {
    name = other.name;
    point = other.point;
    return *this;
}

const std::string &Enemy::getName() const {
    return name;
}

Point Enemy::getPoint() const {
    return point;
}

Enemy::~Enemy() {}

Bullet* Enemy::shoot() {
    Bullet* bullet = new Bullet(Point(point.getX() - 1, point.getY()), "e_bullet");
    return bullet;
}

void Enemy::move(const Point& shift) {
    point = point + shift;
}

bool Enemy::isDead() const {
    return dead;
}

void Enemy::setDead(bool value) {
    dead = value;
}

void Enemy::setNewPosition(Point newPoint) {
    point = newPoint;
}