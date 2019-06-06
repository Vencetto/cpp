#ifndef ENEMY_HPP
#define ENEMY_HPP


#include <string>
#include "FlyObject.hpp"
#include "IShooter.hpp"


class Enemy : public FlyObject, IShooter {
public:

    Enemy();
    Enemy(const Point& point);
    Enemy(const Enemy& other);
    Enemy& operator=(const Enemy& other);
    ~Enemy();
    virtual Bullet* shoot();
    bool isDead() const;
    void setDead(bool isDead);

    const std::string &getName() const;

    Point getPoint() const;
    virtual void move(const Point& shift);
    virtual void setNewPosition(Point point);

private:

    std::string name;
    Point point;
    bool dead;
};


#endif //ENEMY_HPP
