//
// Created by Volodymyr ZOMBER
//

#ifndef EX02_A_HPP
#define EX02_A_HPP

#include "Base.hpp"

class A : public Base {

public:
	A();
	A(A const & src);
	virtual ~A();
	A &	operator=( A const & rhs);

};


#endif //EX02_A_HPP
