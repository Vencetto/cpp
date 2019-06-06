#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int r = (rand() % 10) % 3;

	if (r == 0)
		return (new A);
	else if (r == 1)
		return (new B);
	return (new C);
}

void	identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "no" << std::endl;
}

void	identity_from_reference(Base &p)
{
	try {

		A &ref = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)ref;
	}
	catch (std::bad_cast &bc) {
		try {
			B &ref = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			(void)ref;
		}
		catch (std::bad_cast &bc) {
			try {
				C &ref = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				(void)ref;
			}
			catch (std::bad_cast &bc){
				std::cout << "bad cast" << std::endl;
			}
		}
	}
}

int main() {

	srand(time(NULL));

	Base *base = generate();
	identify_from_pointer(base);
	delete base;

	base = generate();
	identity_from_reference(*base);
	delete(base);
	return 0;
}
