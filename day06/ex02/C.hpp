//
// Created by Volodymyr ZOMBER
//

#ifndef EX02_C_HPP
#define EX02_C_HPP

#include "Base.hpp"

class C : public Base {

public:
	C();
	C(C const & src);
	virtual ~C();
	C &	operator=( C const & rhs);

};


#endif //EX02_C_HPP
