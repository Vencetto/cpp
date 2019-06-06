
#ifndef PEON_HPP
# define PEON_HPP

#include "Sorcerer.hpp"

class Peon : public Victim {

public:

						~Peon();
						Peon(Peon const & src);
	Peon				&operator=(Peon const & src);

	explicit			Peon(std::string name);
	void				getPolymorphed() const;

private:

	Peon();
};

std::ostream	&operator<<(std::ostream &out, const Peon &src);

#endif