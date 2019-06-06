//
// Created by Volodymyr ZOMBER
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include <iostream>

class Enemy {

protected:
	int			_hp;
	std::string	_type;

public:
	Enemy();
	virtual ~Enemy();
	Enemy(Enemy const & src);
	Enemy &operator=(Enemy const & src);

	Enemy(int hp, std::string const & type);
	std::string		getType() const;
	int				getHP() const;
	virtual void	takeDamage(int);

};


#endif //ENEMY_HPP
