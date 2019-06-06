#include "span.hpp"

int main() {

	try {
		Span sp = Span(5);
		Span sp2 = Span(17);

		sp.addNumber(5);
		sp.addNumber(1);

		sp.addNumber(60);
		sp.addNumber(100);
		sp.addNumber(3);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		sp2.addNumber(1);
		sp2.addNumber(12);
		sp2.addNumber(42);
		sp2.addNumber(-200);
		sp2.addNumber(-1010100101);
		sp2.addNumber(200);

		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::string &str) {
		std::cout << str;
	}

	return 0;
}