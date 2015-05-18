#pragma once

#include "Board.h"
#include "Piece.h"
#include "Helper.h"

#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <conio.h>

#define WAIT_TIME 200 // time before piece falls in miliseconds

/**
* Singleton class, as we only need one active game
*/

class Game
{
public:
	static Game* get_instance();
	~Game() {};

	void play();

private:
	Game() {}; // private constructor
	static Game* instance;
};
