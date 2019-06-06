#include <iostream>
#include "easyfind.hpp"
#include <list>

template < typename T >
void	search_in_container(int n, T &container)
{
	std::cout << n << ": ";
	try 	{
		easyfind<T >(container, n);
	}
	catch (std::string &str) {
		std::cout << str << std::endl;
	}
}

int
main(void)
{
	std::list<int>	list;

	list.push_back(2);
	list.push_front(4);
	list.push_back(8);
	list.push_front(16);
	list.push_back(32);

	search_in_container(1, list);
	search_in_container(4, list);
	search_in_container(17, list);
	search_in_container(32, list);

	std::cout << std::endl;
	std::list<char>	listChar;

	listChar.push_back(97);
	listChar.push_front(110);
	listChar.push_back(100);
	listChar.push_front(42);
	listChar.push_back(66);

	search_in_container(42, listChar);
	search_in_container(111, listChar);
	search_in_container(97, listChar);
	search_in_container(33, listChar);

	return (0);
}