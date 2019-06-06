//
// Created by Volodymyr ZOMBER on 2019-04-13.
//

#ifndef RUSH01_GKRELLM_HPP
#define RUSH01_GKRELLM_HPP


#include <ncurses.h>
#include "firstModule.hpp"
#include "secondModule.hpp"

class gkrellm {


public:
	gkrellm();
	virtual ~gkrellm();
	gkrellm(gkrellm const & src);
	gkrellm &operator=(gkrellm const & src);

	firstModule firstModule1;
	secondModule secondModule1;
	void	showModules();

private:
	WINDOW *_mainWin;

};


#endif //RUSH01_GKRELLM_HPP
