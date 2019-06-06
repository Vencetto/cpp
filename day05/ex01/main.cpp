# include "Bureaucrat.hpp"
# include "Form.hpp"

int main() {
	Bureaucrat 	crat(5, "crat");
	Bureaucrat 	bure;

	bure = crat;

	std::cout << "Crat:" << std::endl << crat << std::endl;
	std::cout << "Crat assigned:" << std::endl << bure << std::endl;

	try {
		Form	f1("f1", 1, 1);
		Form	f2("f2", 6, 6);
		Form	f3("f3", 4, 4);

		std::cout << crat << std::endl;
		crat.signForm(f1);
		bure.signForm(f2);
		crat.incGrade();
		crat.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}