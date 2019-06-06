
#ifndef SORCERER_HPP
# define SORCERER_HPP

# include "Victim.hpp"

class Sorcerer {

public:

				Sorcerer(std::string name, std::string title);
				Sorcerer(Sorcerer const & src);
	Sorcerer &	operator=(Sorcerer const & src);
				~Sorcerer();

	std::string		getName() const;
	std::string		getTitle() const;
	void			polymorph(Victim const &src) const;

private:

	std::string		_name;
	std::string		_title;

	Sorcerer();
};

std::ostream	&operator<<(std::ostream &out, const Sorcerer &src);

#endif