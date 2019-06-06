//
// Created by Volodymyr ZOMBER
//

#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy {

public:
	RadScorpion();
	~RadScorpion();
	RadScorpion(RadScorpion const & src);
	RadScorpion &operator=(RadScorpion const & src);

//	void takeDamage(int damage);
};


#endif //RADSCORPION_HPP
