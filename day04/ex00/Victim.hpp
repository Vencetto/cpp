
#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>
# include <iostream>

class Victim {

public:

					Victim(std::string name);
	virtual			~Victim();
					Victim(Victim const & src);
	Victim &		operator=(Victim const & src);

	std::string		getName() const;
	virtual void	getPolymorphed() const;


protected:

	Victim();
	std::string		_name;

};

std::ostream	&operator<<(std::ostream &out, const Victim &src);

#endif