#ifndef METHEORITE_HPP
#define METHEORITE_HPP


#include <string>
#include "FlyObject.hpp"
#include "IShooter.hpp"


class Metheorite : public FlyObject {
public:

    Metheorite();
    Metheorite(const Point& point);
    Metheorite(const Metheorite& other);
    Metheorite& operator=(const Metheorite& other);
    ~Metheorite();

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


#endif //METHEORITE_HPP
