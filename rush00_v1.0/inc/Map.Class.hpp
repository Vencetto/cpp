
#ifndef MAPCLASS_HPP
# define MAPCLASS_HPP

# define WIN_HEIGHT 60
# define WIN_LENGTH 210

# include <iostream>
# include <ncurses.h>
# include "Point.hpp"

class Map {


public:

	Map();
	~Map();
	Map(Map const &src);
	Map &operator=(Map const &src);

	void	draw(struct timespec &timer, int score, int level) const;
	void	drawObj(Point point, std::string name, int color = 0);
	void	exitNcurs() const;
	void	putChar(std::string win, int x, int y, std::string str, int color);
	void	refreshAll();
	void	gameOver() ;
private:

	char	_field[60][210];
	int		_fLen;
	int		_fHight;
	int		_lives;
	WINDOW	*_mainWin;
	WINDOW	*_sideWin;
	void	drawSideWin(struct timespec &timer, int score, int level) const;
	void	drawMainWin() const ;

};

#endif