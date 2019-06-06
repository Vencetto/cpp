//
// Created by Volodymyr ZOMBER
//

#ifndef EX02_ARRAY_HPP
#define EX02_ARRAY_HPP

#include <exception>
#include <iostream>

template < typename T >
class Array {

public:

	Array<T>(): _array(NULL), _len(0){};

	explicit Array<T>(unsigned int n) : _len(n) {
		_array = new T[n];
	};

	~Array<T>() {};

	Array<T>(Array const &src) {
		*this = src;
	};

	Array<T> &operator=(Array const &src) {
		delete this->_array;
		this->_len = src._len;
		this->_array = new T[this->_len];
		for (int i = 0; i < this->_len; i++)
			this->_array[i] = src._array[i];
		return *this;
	};

	T &operator[](int n) {
		if (n < 0 || n > this->_len)
			throw std::exception();
		return this->_array[n];
	}

	int	size() {
		return _len;
	}

private:
	T		*_array;
	int		_len;
};

#endif //EX02_ARRAY_HPP
