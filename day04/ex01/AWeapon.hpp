
#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>
# include <iostream>

class AWeapon {

private:

		std::string	_name;
		int			_damage;
		int			_apcost;
		AWeapon();

public:

	AWeapon(AWeapon const &src);
	AWeapon &operator=(AWeapon const & src);
	AWeapon(std::string const & name, int apcost, int damage);
	~AWeapon();

	std::string		getName() const;
	int				getAPCost() const;
	int				getDamage() const;

	virtual void attack() const = 0;
};

#endif
