//
// Created by Volodymyr ZOMBER
//

#ifndef EX02_MUTANTSTACK_HPP
#define EX02_MUTANTSTACK_HPP

#include <stack>
#include <list>

template < typename T >
class MutantStack : public std::stack<T>{

public:
	MutantStack<T>(){ };
	~MutantStack<T>(){ };
	MutantStack<T>(MutantStack const& src) { *this = src; };
	MutantStack<T> & operator=(MutantStack const & src) {
			this->_stack.assign(src._stack.begin(), src._stack.end());
		return *this;
	};
	T empty() { return _stack.empty(); }
	T size() { return _stack.size(); }
	T top() { return _stack.front(); }
	void push(T value) { return _stack.push_front(value); }
	void pop() { return _stack.pop_front(); };
	typedef std::list<int>::iterator iterator;
	iterator begin() { return _stack.begin(); };
	iterator end() { return _stack.end(); };

private:
	std::list<T>	_stack;

};


#endif //EX02_MUTANTSTACK_HPP
