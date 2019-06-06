//
// Created by Volodymyr ZOMBER
//

#ifndef EX02_B_HPP
#define EX02_B_HPP

#include "Base.hpp"

class B : public Base {

public:
	B();
	B(B const & src);
	virtual ~B();
	B &	operator=( B const & rhs);

};


#endif //EX02_B_HPP
