//
// Created by Volodymyr ZOMBER
//

#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine : public ISpaceMarine {

public:
	TacticalMarine();
	~TacticalMarine();
	TacticalMarine(TacticalMarine const & src);
	TacticalMarine &operator=(TacticalMarine const & src);

	ISpaceMarine*	clone() const;
	void			battleCry() const;
	void			rangedAttack() const;
	void			meleeAttack() const;
};


#endif //TACTICALMARINE_HPP
