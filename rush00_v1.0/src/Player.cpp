#include "Player.hpp"

Player::Player() : name("player") {}

Player::Player(const Player &other) {
    *this = other;
}

Player::Player(const Point &point) : name("player"), point(point) {}

Player& Player::operator=(const Player &other) {
    name = other.name;
    point = other.point;
    return *this;
}

Player::~Player() {}

const std::string &Player::getName() const {
    return name;
}

Point Player::getPoint() const {
    return point;
}

Bullet* Player::shoot() {
    Bullet* bullet = new Bullet(Point(point.getX() + 1, point.getY()), "bullet");
    return bullet;
}

void Player::move(const Point& shift) {
    point = point + shift;
}

bool Player::isDead() const {
    return dead;
}

void Player::setDead(bool value) {
    dead = value;
}

void Player::setNewPosition(Point newPoint) {
    point = newPoint;
}