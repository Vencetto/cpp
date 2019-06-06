//
// Created by Volodymyr ZOMBER
//

#ifndef EX00_EASYFIND_HPP
#define EX00_EASYFIND_HPP

#include <iostream>
#include <string>

template < typename T >
void	easyfind( T &container, int n) {

	typename T::iterator i;

	i = std::find(container.begin(), container.end(), n);

	if (i != container.end())
	{
		std::cout << "Found " << std::endl;
	}
	else
		throw (std::string("Didn't find"));
}

#endif //EX00_EASYFIND_HPP
