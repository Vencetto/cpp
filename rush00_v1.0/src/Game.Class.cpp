
#include "Game.Class.hpp"

/*___________________Coplien's form__________________________*/

Game::Game() {  // initialize map
	std::cout << "Game Constructor is called." << std::endl;
}

Game::~Game() {
	std::cout << "Game Destructor is called." << std::endl;
}

Game::Game(Game const &src) {
	if (this != &src)
		*this = src;
}

Game& Game::operator=(Game const &src) {
	this->map = src.map;
	return *this;
}