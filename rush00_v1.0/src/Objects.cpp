#include <iostream>
#include "Objects.hpp"
#include "Metheorite.hpp"
#include "Enemy.hpp"

Objects::Objects() : size(0), bullet_num(0), enemy_bullets(0) {
    player = new Player(Point(4, 28));
}

Objects::Objects(const Objects &other) {
    *this = other;
}

Objects& Objects::operator=(const Objects &other) {
    player = new Player(*other.player);
    size = other.size;
    bullet_num = other.bullet_num;
    for (unsigned int i = 0; i < size; i++) {
        flyObjects[i] = other.flyObjects[i];
    }
    return *this;
}

Objects::~Objects() {}

int Objects::addObject(FlyObject* obj) {
    if (size == OBJ_MAX_SIZE) {
//        for (unsigned int i = 0; i < size; i++) {
//            if (flyObjects[i]->isDead()) {
//                delete flyObjects[i];
//                flyObjects[i] = obj;
//                return 1;
//            }
//        }
        delete obj;
        return -1;
    }
    if (obj->getName() == "e_bullet") {
        if (enemy_bullets <= ENEMY_BULLET_MAX_NUM) {
            flyObjects[size++] = obj;
            enemy_bullets++;
        } else {
            delete obj;
        }
    return 0;
    }
    flyObjects[size++] = obj;

    return 0;
}

void Objects::deleteObject(unsigned int i) {
    flyObjects[i]->setDead(true);
}

FlyObject *const *Objects::getFlyObjects() const {
    return flyObjects;
}

Player *Objects::getPlayer() const {
    return player;
}

unsigned int Objects::getSize() const {
    return size;
}

Bullet *const *Objects::getBullets() const {
    return bullets;
}

bool Objects::addBullet(Bullet* obj) {
    if (bullet_num == BULLET_MAX_NUM) {
        for (unsigned int i = 0; i < bullet_num; i++) {
            if (bullets[i]->isDead()) {
                delete bullets[i];
                bullets[i] = obj;
                return true;
            }
        }
        return false;
    }
    bullets[bullet_num++] = obj;
    return true;
}

void Objects::deleteBullet(const Point& point) {
    for (unsigned int i = 0; i < bullet_num; i++) {
        if (!bullets[i]->isDead() && bullets[i]->getPoint() == point) {
            bullets[i]->setDead(true);
        }
    }
}

unsigned int Objects::getBullet_num() const {
    return bullet_num;
}

std::ostream& operator<<(std::ostream& o, const Objects& objects) {
    for (unsigned int i = 0; i < objects.getSize(); i++) {
        if (!objects.getFlyObjects()[i]->isDead()) {
            o << "Name: " << objects.getFlyObjects()[i]->getName() << ", "
              << "x = " << objects.getFlyObjects()[i]->getPoint().getX() << ", "
              << "y = " <<  objects.getFlyObjects()[i]->getPoint().getY() << std::endl;
        }
    }
    return o;
}