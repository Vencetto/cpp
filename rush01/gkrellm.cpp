//
// Created by Volodymyr ZOMBER on 2019-04-13.
//

#include "gkrellm.hpp"

gkrellm::gkrellm() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);

	this->_mainWin = newwin(30, 70, 1, 3);
	nodelay(stdscr, true);
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);

	init_pair(44, COLOR_YELLOW, COLOR_YELLOW);

	refresh();
	wrefresh(this->_mainWin);
}

gkrellm::~gkrellm() {
	delwin(this->_mainWin);
	endwin();
}

gkrellm::gkrellm(gkrellm const &src) {
	*this = src;
}

gkrellm& gkrellm::operator=(gkrellm const &src) {
	this->_mainWin = src._mainWin;
	return *this;
}

void gkrellm::showModules() {

	wattron(this->_mainWin, COLOR_PAIR(4));
	mvwprintw(_mainWin, 2, 12, "MAC INFO");
	wattroff(this->_mainWin, COLOR_PAIR(4));
	wattron(this->_mainWin, COLOR_PAIR(3));
	mvwprintw(_mainWin, 3, 3, firstModule1.getOs()->str1);
	mvwprintw(_mainWin, 4, 3, firstModule1.getOs()->str2);
	mvwprintw(_mainWin, 5, 3, firstModule1.getOs()->str3);
	wattroff(this->_mainWin, COLOR_PAIR(3));

	wattron(this->_mainWin, COLOR_PAIR(4));
	mvwprintw(_mainWin, 7, 12, "HOSTNAME");
	wattroff(this->_mainWin, COLOR_PAIR(4));
	wattron(this->_mainWin, COLOR_PAIR(3));
	mvwprintw(_mainWin, 8, 9, firstModule1.getHost());
	wattroff(this->_mainWin, COLOR_PAIR(3));

	wattron(this->_mainWin, COLOR_PAIR(4));
	mvwprintw(_mainWin, 10, 12, "DATE TIME");
	wattroff(this->_mainWin, COLOR_PAIR(4));

	clock_t prevTime = clock();
	while (TRUE)
	{
		while (clock() - prevTime < CLOCKS_PER_SEC / 150)
			;
		prevTime = clock();

		wattron(this->_mainWin, COLOR_PAIR(3));
		mvwprintw(this->_mainWin, 11, 7, firstModule1.getTime());
		wattroff(this->_mainWin, COLOR_PAIR(3));

		wattron(this->_mainWin, COLOR_PAIR(2));
		mvwprintw(this->_mainWin, 15, 7, secondModule1.getCpu());
		wattroff(this->_mainWin, COLOR_PAIR(2));

		wattron(this->_mainWin, COLOR_PAIR(2));
		mvwprintw(this->_mainWin, 17, 7, firstModule1.getNet());
		wattroff(this->_mainWin, COLOR_PAIR(2));

		wattron(this->_mainWin, COLOR_PAIR(2));
		mvwprintw(this->_mainWin, 19, 7, firstModule1.getRam());
		wattroff(this->_mainWin, COLOR_PAIR(2));

		wattron(this->_mainWin, COLOR_PAIR(44));
		box(this->_mainWin, '#', '#');
		wattroff(this->_mainWin, COLOR_PAIR(44));
		
		wrefresh(this->_mainWin);
	}

}
