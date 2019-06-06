//
// Created by Volodymyr ZOMBER
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Enemy.hpp"
#include "AWeapon.hpp"

class Character {

private:
	std::string	_name;
	int			_numberAp;
	AWeapon		*_weapon;
	~Character();

public:
	Character(std::string const & name);
	Character();
	void recoverAP();
	void equip(AWeapon *weapon);
	void attack(Enemy *enemy);
	std::string getName() const;
	AWeapon *getWeapon() const;
	int getAp() const;

	Character(Character const & src);
	Character &operator=(Character const & src);
};

std::ostream	&operator<<(std::ostream &out, const Character &src);

#endif //CHARACTER_HPP
