#ifndef OBJECTS_H
#define OBJECTS_H

#include "Player.hpp"
#include "Metheorite.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

#define OBJ_MAX_SIZE 30
#define BULLET_MAX_NUM 50
#define ENEMY_BULLET_MAX_NUM 3

class Objects {

public:
    Objects();
    Objects(const Objects& other);
    Objects& operator=(const Objects& other);
    ~Objects();

    int addObject(FlyObject* obj);
    void deleteObject(unsigned int i);
    bool addBullet(Bullet* obj);
    void deleteBullet(const Point& point);

    unsigned int getSize() const;

    FlyObject *const *getFlyObjects() const;

    Player *getPlayer() const;

    Bullet *const *getBullets() const;

    unsigned int getBullet_num() const;

private:
    Player* player;
    FlyObject* flyObjects[OBJ_MAX_SIZE];
    Bullet* bullets[BULLET_MAX_NUM];
    unsigned int size;
    unsigned int bullet_num;
    unsigned int enemy_bullets;
};

std::ostream& operator<<(std::ostream& o, const Objects& objects);

#endif //OBJECTS_H
