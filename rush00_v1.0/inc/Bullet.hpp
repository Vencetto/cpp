#ifndef BULLET_HPP
#define BULLET_HPP


#include <string>
#include "FlyObject.hpp"

class Bullet : public FlyObject {
public:

    Bullet(const Bullet& other);
    Bullet(const Point& point, std::string name);
    Bullet& operator=(const Bullet& other);
    ~Bullet();

    const std::string &getName() const;
    bool isDead() const;
    void setDead(bool isDead);

    Point getPoint() const;
    virtual void move(const Point& shift);
    void setNewPosition(Point point);


protected:
    Bullet();

private:
    std::string name;
    Point point;
    bool dead;
};


#endif //BULLET_HPP
