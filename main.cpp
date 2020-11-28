#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"

int main() {

	srand((unsigned)time(NULL));
	Game game;
	game.run();

	return 0;
}