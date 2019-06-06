#ifndef SHOOTER_HPP
#define SHOOTER_HPP

#include <string>
#include "Bullet.hpp"

class IShooter {

public:
    virtual Bullet* shoot() = 0;
};


#endif //SHOOTER_HPP
