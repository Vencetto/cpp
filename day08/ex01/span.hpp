//
// Created by Volodymyr ZOMBER
//

#ifndef EX01_SPAN_HPP
#define EX01_SPAN_HPP

#include <exception>
#include <iostream>
#include <vector>

class Span {

public:

	void	addNumber(int n);
	int		shortestSpan() const;
	int		longestSpan() const;
	~Span();
	Span(unsigned int n);
	Span(Span const &src);
	Span &operator=(Span const &src);

private:

	unsigned int		_N;
	std::vector<int>	_container;
	Span();

};


#endif //EX01_SPAN_HPP
