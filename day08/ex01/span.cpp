//
// Created by Volodymyr ZOMBER
//

#include "span.hpp"
#include <algorithm>
#include <iterator>

/*____________________Coplien's form_________________________*/

Span::Span() : _N(0), _container(0) {};

Span::~Span() {}

Span::Span(Span const &src) {
	if (this != &src)
		*this = src;
}

Span& Span::operator=(Span const &src) {

	this->_N = src._N;
	this->_container.operator=(src._container);

	return *this;
}

Span::Span(unsigned int n) : _N(n) {
	_container.reserve(n);
}

/*_________________________Mehods____________________________*/

void Span::addNumber(int n) {

	if (_container.size() < _N)
		_container.push_back(n);
	else
		throw (std::string("\nThere already are MAX of elements stored in the object"));
}

int Span::shortestSpan() const {

	if (this->_container.size() <= 1)
		throw (std::string("not enought elements in the object"));

	std::vector<int>::const_iterator runner;
	std::vector<int>::const_iterator iter = this->_container.begin();
	int minSpan = *std::max_element(this->_container.begin(), this->_container.end());;

	while (iter != this->_container.end())
	{
		runner = this->_container.begin();
		while (runner != this->_container.end())
		{
			if (abs(*iter - *runner) < minSpan && abs(*iter - *runner) > 0)
				minSpan = abs(*iter - *runner);
			runner++;
		}
		iter++;
	}
	return (minSpan);
}

int Span::longestSpan() const {

	if (this->_container.size() <= 1)
		throw (std::string("not enought elements in the object"));

	return (abs(*std::max_element(_container.begin(), _container.end()) -
							*std::min_element(_container.begin(), _container.end())));
}