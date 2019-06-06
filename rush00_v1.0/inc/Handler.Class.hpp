
#ifndef HANDLER_CLASS_HPP
#define HANDLER_CLASS_HPP

#include "Map.Class.hpp"
#include "Objects.hpp"
#include <ctime>


class Handler {

public:

	Handler();
	~Handler();
	Handler(Handler const &src);
	Handler &operator=(Handler const &src);

	void	startGame();
	void	catchButton();

private:

	void	moveBullets();
	void	moveEnemies();
	void	createNewEnemy();
	void	createNewMeteor();
	void	beShooted();
	void	updateEnemyPosition(unsigned int i);
	void	updateEnemyBulletPosition(unsigned int i);
	bool	killEnemy(Point point);

	Map		*map;
	Objects	*obj;
	int		score;
	int		level;
};

#endif