/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:54:07 by vzomber           #+#    #+#             */
/*   Updated: 2019/01/17 18:54:08 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <ctime>

# define BLUE "\033[34m"
# define RED "\033[31m"
# define CYAN "\033[36m"
# define GREEN "\033[32m"
# define END "\033[0m"

class ClapTrap {

public:
	ClapTrap();
	~ClapTrap();
	ClapTrap (ClapTrap const & src);
	ClapTrap & operator=(ClapTrap const & src);


	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	int			getHitPoints() const;
	int			getMaxHitPoints() const;
	int			getEnergyPoints() const;
	int			getMaxEnergyPoints() const;
	int			getLevel() const;
	std::string	getName() const;
	int			getMeleeAttackDamage() const;
	int			getRangedAttackDamage() const;
	int			getArmorDamageReduction() const;



protected:
	int			hitPoints;
	int			maxHitPoints;
	int			energyPoints;
	int			maxEnergyPoints;
	int			level;
	std::string	name;
	int			meleeAttackDamage;
	int			rangedAttackDamage;
	int			armorDamageReduction;

};

#endif