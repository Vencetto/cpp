#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <string>
#include "FlyObject.hpp"
#include "IShooter.hpp"


class Player : public FlyObject, IShooter {
public:

    Player();
    Player(const Point& point);
    Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();
    virtual Bullet* shoot();

    const std::string &getName() const;
    bool isDead() const;
    void setDead(bool isDead);

    Point getPoint() const;
    virtual void move(const Point& shift);
    void setNewPosition(Point point);

private:

    std::string name;
    Point point;
    bool dead;
};


#endif //PLAYER_HPP
