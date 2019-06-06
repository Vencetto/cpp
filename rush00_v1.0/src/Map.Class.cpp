
#include "Map.Class.hpp"
# include <unistd.h>

/*************************************************************/
/*___________________Coplien's form__________________________*/
/*************************************************************/

Map::Map() {
	this->_fLen = WIN_LENGTH;
	this->_fHight = WIN_HEIGHT;
	this->_lives = 3;

	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	this->_mainWin = newwin(WIN_HEIGHT, WIN_LENGTH, 1, 3);
	this->_sideWin = newwin(5, 30, 61, 3);
	box(this->_mainWin, 0, 0);
	box(this->_sideWin, 0, 0);
	wborder(this->_mainWin, '*', '*', '*', '*', '*', '*', '*', '*');
	wborder(this->_sideWin, '|', '|', '-', '-', '+', '+', '+', '+');
	nodelay(stdscr, true);

	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(10, COLOR_BLACK, COLOR_WHITE);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
	init_pair(12, COLOR_BLACK, COLOR_RED);
	init_pair(13, COLOR_BLACK, COLOR_BLUE);
	init_pair(14, COLOR_BLACK, COLOR_CYAN);
}

Map::~Map() {
	delwin(this->_mainWin);
	delwin(this->_sideWin);
	endwin();
}

Map::Map(Map const &src) {
	if (this != &src)
		*this = src;
}

Map& Map::operator=(Map const &src) {

	this->_fHight = src._fHight;
	this->_fLen = src._fLen;
	this->_mainWin = src._mainWin;
	this->_sideWin = src._sideWin;

	for (int i = 0; i < this->_fHight; i++)
		for (int j = 0; j < this->_fLen; i++)
			this->_field[i][j] = src._field[i][j];

	return *this;
}

/*************************************************************/
/*_________________________Drawing___________________________*/
/*************************************************************/

void Map::draw(struct timespec &timer, int score, int level) const {

	curs_set(0);
	drawSideWin(timer, score, level);
	drawMainWin();

	wborder(this->_mainWin, '*', '*', '*', '*', '*', '*', '*', '*');
	wborder(this->_sideWin, '|', '|', '-', '-', '+', '+', '+', '+');
}

void Map::drawSideWin(struct timespec &timer, int score, int level) const {

	wattron(_sideWin, COLOR_PAIR(2));
	mvwprintw(_sideWin, 1, 1, " YOU HAVE ONLY ONE LIFE!");
	wattroff(_sideWin, COLOR_PAIR(2));

	wattron(_sideWin, COLOR_PAIR(1));
	mvwprintw(_sideWin, 2, 2, "Score: %i ", score);
	wattroff(_sideWin, COLOR_PAIR(1));

	struct timespec here;
	here.tv_sec = 0;
	clock_gettime(CLOCK_MONOTONIC, &here);

	wattron(_sideWin, COLOR_PAIR(1));
	mvwprintw(_sideWin, 2, 18, "Running");
	wattroff(_sideWin, COLOR_PAIR(1));

	wattron(_sideWin, COLOR_PAIR(4));
	mvwprintw(_sideWin, 3, 2, "Time: %i:%i", abs((timer.tv_sec - here.tv_sec) / 60), abs((timer.tv_sec - here.tv_sec) % 60));
	wattroff(_sideWin, COLOR_PAIR(4));

	wattron(_sideWin, COLOR_PAIR(5));
	mvwprintw(_sideWin, 3, 15, "Level: %i", level);
	wattroff(_sideWin, COLOR_PAIR(5));
}

void Map::drawMainWin() const {

	int i, j, t;

	i = 0;
	wattron(_mainWin, COLOR_PAIR(3));
	while (++i < _fHight)
	{
		mvwprintw(_mainWin, i, 1, " ");
		j = 0;
		t = i % 2;
		while (++j < _fLen) {
			if (j % 2 == 0)
				mvwprintw(_mainWin, i, j + t, ".");
			else
				mvwprintw(_mainWin, i, j + t, " ");
		}
	}
	wattroff(_mainWin, COLOR_PAIR(3));
}

void Map::drawObj(Point point, std::string name, int color) {
	char	ch[1];
	int		cl = 0;

	if (name == "player"){
		ch[0] = '>';
		cl = 1;
	}
	else if (name == "enemy"){
		ch[0] = '<';
		cl = 5;
	}
	else if (name == "bullet" || (name == "e_bullet")){
		ch[0] = '-';
		cl = 4;
	}
	else if (name == "meteor"){
		ch[0] = '*';
		cl = 6;
	}
	else {
		ch[0] = '.';
		cl = 10;
	}
	if (color == 2)
		cl = 2;

	wattron(_mainWin, COLOR_PAIR(cl));
	mvwprintw(_mainWin, point.getY(), point.getX(), ch);
	wattroff(_mainWin, COLOR_PAIR(cl));
}

/********************************************************/
/*____________________Ncurses___________________________*/
/********************************************************/

void Map::exitNcurs() const {
	delwin(this->_mainWin);
	delwin(this->_sideWin);
	endwin();
	exit(1);
}

void Map::putChar(std::string c, int y, int x, std::string str, int color) {
	if (c == "_mainWin")
	{
		wattron(_mainWin, COLOR_PAIR(color));
		mvwprintw(_mainWin, y, x, str.c_str());
		wattroff(_mainWin, COLOR_PAIR(color));
		wrefresh(this->_mainWin);
	}
	else if (c == "_sideWin")
	{
		wattron(_sideWin, COLOR_PAIR(color));
		mvwprintw(_sideWin, y, x, str.c_str());
		wattroff(_sideWin, COLOR_PAIR(color));
		wrefresh(this->_sideWin);
	}
}

void Map::refreshAll() {
	wrefresh(this->_mainWin);
	wrefresh(this->_sideWin);
}

void Map::gameOver() {
	wattron(_mainWin, COLOR_PAIR(4));
	mvwprintw(_mainWin, 20, 20, "  @@@@@    @ @@    @ @   @@  @ @@@@@       @@@@@    @    @  @ @@@@  @ @@@  ");
	mvwprintw(_mainWin, 21, 20, " @     @   @  @@   @  @ @ @  @            @     @   @    @  @       @    @ ");
	mvwprintw(_mainWin, 22, 20, "@          @    @  @   @  @  @           @       @  @    @  @       @    @ ");
	mvwprintw(_mainWin, 23, 20, "@          @ @@@@  @      @  @ @@@@@     @       @  @    @  @ @@@@  @ @@@  ");
	mvwprintw(_mainWin, 24, 20, "@    @@@@  @    @  @      @  @           @       @  @    @  @       @   @  ");
	mvwprintw(_mainWin, 25, 20, " @     @   @    @  @      @  @            @     @    @   @  @       @    @ ");
	mvwprintw(_mainWin, 26, 20, "  @@@@@    @    @  @      @  @ @@@@@       @@@@@      @@@   @ @@@@  @     @");
	mvwprintw(_mainWin, 27, 20, "           ESC TO EXIT (You're still great, your mom loves you)            ");
	wattroff(_mainWin, COLOR_PAIR(4));
	refreshAll();
	while (getch() != 27)
		;
	exitNcurs();
}