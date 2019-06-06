#ifndef FLYOBJECT_HPP
#define FLYOBJECT_HPP


#include <string>
#include "Point.hpp"

class FlyObject {
public:
    virtual ~FlyObject() {}

    virtual void move(const Point& shift) = 0;

    virtual const std::string &getName() const = 0;
    virtual Point getPoint() const = 0;

    virtual bool isDead() const = 0;
    virtual void setDead(bool isDead) = 0;
    virtual void setNewPosition(Point point) = 0;
};


#endif //FLYOBJECT_HPP
