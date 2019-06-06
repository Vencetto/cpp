
#include "Handler.Class.hpp"
#include <stdio.h>

/*************************************************************/
/*___________________Coplien's form__________________________*/
/*************************************************************/

Handler::Handler() : score(0), level(0) {
	this->map = new Map();
	this->obj = new Objects();
}

Handler::~Handler() {
}

Handler::Handler(Handler const &src) {
	if (this != &src)
		*this = src;
}

Handler& Handler::operator=(Handler const &src) {
	this->obj = src.obj;
	this->map = src.map;
	return *this;
}

/*************************************************************/
/* _______________________START______________________________*/
/*************************************************************/

void Handler::startGame() {

	struct timespec		tstart;
	struct timespec		tend;
	struct timespec		timer;

	nodelay(stdscr, true);
	timer.tv_sec = 0;
	tstart.tv_nsec = 0;
	tstart.tv_sec = 0;
	tend.tv_nsec = 0;
	tend.tv_sec = 0;
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	clock_gettime(CLOCK_MONOTONIC, &timer);

	int k = 0;
	while (true)
	{
		clock_gettime(CLOCK_MONOTONIC, &tend);
		this->catchButton();
		if (((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec) - ((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec) > 0.0001)
		{
			map->draw(timer, score, level);
			for (unsigned int i = 0; i < obj->getSize(); i++) {
				map->drawObj(obj->getFlyObjects()[i]->getPoint(), obj->getFlyObjects()[i]->getName());
			}
			for (unsigned int i = 0; i < obj->getBullet_num(); i++) {
				map->drawObj(obj->getBullets()[i]->getPoint(), obj->getBullets()[i]->getName());
			}
			if (k % 5 == 0)
				moveBullets();
			if (k % 25 == 0)
				moveEnemies();
			if (k % 200 == 0) {
				createNewMeteor();
			}
			if (k % 400 == 0) {
				createNewEnemy();
			}
			if (k % 1000 == 0) {
				beShooted();
				k = 0;
			}
			level = score / 10;
			map->drawObj(obj->getPlayer()->getPoint(), obj->getPlayer()->getName());
			map->refreshAll();
			tstart.tv_nsec = tend.tv_nsec;
			tstart.tv_sec = tend.tv_sec;
			k++;
		}
		if (k == 10000)
			break;
	}
}

void Handler::catchButton() {

	int 	ch;
	Player* player = obj->getPlayer();

	ch = getch();
	if (ch == 27) // esc
		map->exitNcurs();
	if (ch == KEY_LEFT) { // <-
		if (player->getPoint().getX() > 2) {
			player->move(Point(-1, 0));
		}
	}
	if (ch == KEY_RIGHT) {// ->
		if (player->getPoint().getX() < WIN_LENGTH - 2) {
			player->move(Point(1, 0));
		}
	}
	if ( ch == KEY_DOWN) {// down
		if (player->getPoint().getY() < WIN_HEIGHT - 2) {
			player->move(Point(0, 1));
		}
	}
	if (ch == KEY_UP) // up
	{
		if (player->getPoint().getY() > 1) {
			player->move(Point(0, -1));
		}
	}
	if (ch == 32) { // space
		obj->addBullet(obj->getPlayer()->shoot());
	}
	if (ch == 112) {
		map->putChar("_sideWin", 2, 18, "Pause  ", 2);
		while (getch() != 112)
			;
		map->putChar("_sideWin", 2, 18, "Running", 1);
	}
}

void Handler::moveBullets() {

	for (unsigned int i = 0; i < obj->getBullet_num(); i++) {
		Bullet *object = obj->getBullets()[i];
		object->move(Point(1, 0));
		if (killEnemy(object->getPoint())) {
			score++;
		}
		if (object->getPoint().getX() >= 209) {
			obj->deleteBullet(object->getPoint());
		}
	}
	for (unsigned int i = 0; i < obj->getSize(); i++) {
		FlyObject *object = obj->getFlyObjects()[i];
		if (object->getName() == "e_bullet") {
			object->move(Point(-1, 0));
			if (object->getPoint() == obj->getPlayer()->getPoint()) {
				map->gameOver();
			}
			if (object->getPoint().getX() <= 1) {
//				obj->deleteObject(i);
				updateEnemyBulletPosition(i);
			}
		}
	}
}

void Handler::moveEnemies() {

	for (unsigned int i = 0; i < obj->getSize(); i++)
	{
		if (obj->getFlyObjects()[i]->getName() == "meteor" | obj->getFlyObjects()[i]->getName() == "enemy") {
			obj->getFlyObjects()[i]->move(Point(-1, 0));
			if (obj->getFlyObjects()[i]->getPoint() == obj->getPlayer()->getPoint()) {
				map->gameOver();
			}
			if (obj->getFlyObjects()[i]->getPoint().getX() <= 1) {
				updateEnemyPosition(i);
			}
		}
	}
}

void Handler::createNewEnemy() {
	int randomY = (rand() % 1000) % (WIN_HEIGHT - 2) + 1;
	Enemy* enemy = new Enemy(Point(WIN_LENGTH, randomY));
	obj->addObject(enemy);
}

void Handler::createNewMeteor() {
	int randomY = (rand() % 1000) % (WIN_HEIGHT - 2) + 1;
	Metheorite* enemy = new Metheorite(Point(WIN_LENGTH, randomY));
	obj->addObject(enemy);
}

void Handler::updateEnemyPosition(unsigned int pos) {
	int randomY = (rand() % 1000) % (WIN_HEIGHT - 2) + 1;
	obj->getFlyObjects()[pos]->setNewPosition(Point(WIN_LENGTH, randomY));
	obj->getFlyObjects()[pos]->setDead(false);

}

bool Handler::killEnemy(Point point) {
	for (unsigned int i = 0; i < obj->getSize(); i++) {
		FlyObject* enemy = obj->getFlyObjects()[i];
		if ( enemy->getPoint() == point && (enemy->getName() == "meteor" || enemy->getName() == "enemy")) {
			enemy->setDead(true);
			updateEnemyPosition(i);
			return true;
		}
	}
	return false;
}

void Handler::beShooted() {
	for (unsigned int i = 0; i < obj->getSize(); i++) {
		if (obj->getFlyObjects()[i]->getName() == "enemy") {
			Enemy* enemy = (Enemy*)obj->getFlyObjects()[i];
			obj->addObject(enemy->shoot());
		}
	}
}

void Handler::updateEnemyBulletPosition(unsigned int pos) {
    while(1) {
        int random = (rand() % 100) % obj->getSize();
		if (obj->getFlyObjects()[random]->getName() == "enemy") {
			Point newPoint(obj->getFlyObjects()[random]->getPoint() + Point(-1, 0));
			obj->getFlyObjects()[pos]->setNewPosition(newPoint);
			break;
		}
	}
}