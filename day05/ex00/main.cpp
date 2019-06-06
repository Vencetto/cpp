# include "Bureaucrat.hpp"

int main() {
	Bureaucrat 	crat(5, "crat");
	Bureaucrat 	bure;

	bure = crat;

	std::cout << "Crat:" << std::endl << crat << std::endl;
	std::cout << "Crat assigned:" << std::endl << bure << std::endl;

	try {
		Bureaucrat 	bur1(0, "steeve");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat 	bur2(180, "also_Steeve");
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	Bureaucrat	bur3(50, "Rob");
	try {
		bur3.incGrade();
		std::cout << bur3 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
		bur3.decGrade();
		std::cout << bur3 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}