#include <iostream>
#include <stdexcept>

int main(int ac, char **av) {

	if (ac != 2) {
		std::cout << "only with one parameter, please." << std::endl;
		return 0;
	}

	char *str = av[1];
	// char
	{
		char c;
		std::cout << "char: ";
		try {
			c = std::stoi(str);
		if (isprint(c))
			std::cout << "'" << c << "'" <<  std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "impossible" << std::endl;
		}
	}

	// int
	{
		std::cout << "int: ";
		try {
			std::cout << std::stoi(str) << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "impossible" << std::endl;
		}
	}

	std::cout.precision(1);

	// float
	{
		std::cout << "float: ";
		try {
			std::cout << std::fixed << std::stof(str) << 'f' << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "impossible" << std::endl;
		}
	}

	// double
	{
		std::cout << "double: ";
		try {
			std::cout << std::fixed << std::stof(str) << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "impossible" << std::endl;
		}
	}
	return 0;
}
