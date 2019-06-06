//
// Created by Volodymyr ZOMBER
//

#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISquad.hpp"

class Squad : public ISquad {

	typedef struct		s_marineList
	{
		ISpaceMarine		*marine;
		struct s_marineList	*next;
	}					t_marineList;

private:
	int						_count;
	struct s_marineList*	_marinList;

public:
	Squad();
	~Squad();
	Squad(Squad const & src);
	Squad &operator=(Squad const & src);

	int				getCount() const;
	ISpaceMarine*	getUnit(int n) const;
	int				push(ISpaceMarine *src);
};


#endif //SQUAD_HPP
