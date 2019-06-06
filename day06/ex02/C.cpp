//
// Created by Volodymyr ZOMBER
//

#include "C.hpp"

C::C(){}

C::C(C const & src){
	*this = src;
}

C::~C() {}

C & C::operator=(C const & rhs) {
	(void)rhs;
	return *this;
}