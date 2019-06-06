
#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

#include "Map.Class.hpp"

class Game {

public:

			Game();
			~Game();
			Game(Game const & src);
	Game	&operator=(Game const & src);
	Map		map;

private:


};

#endif