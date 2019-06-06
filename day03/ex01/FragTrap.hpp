/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:52:13 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/13 18:52:14 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define END "\033[0m"

class FragTrap {

public:

/* Constructors and destructor */

	FragTrap();
	explicit FragTrap(std::string name);
	~FragTrap();
	FragTrap(FragTrap const & src);

/* Operator */

	FragTrap & operator=(FragTrap const & rhs);

/* Methods */

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);

	int			getHitPoints() const;
	int			getMaxHitPoints() const;
	int			getEnergyPoints() const;
	int			getMaxEnergyPoints() const;
	int			getLevel() const;
	std::string	getName() const;
	int			getMeleeAttackDamage() const;
	int			getRangedAttackDamage() const;
	int			getArmorDamageReduction() const;

private:

/* Attributes */

	int			_hitPoints;
	int			_maxHitPoints;
	int			_energyPoints;
	int			_maxEnergyPoints;
	int			_level;
	std::string	_name;
	int			_meleeAttackDamage;
	int			_rangedAttackDamage;
	int			_armorDamageReduction;

};

#endif
