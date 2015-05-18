#include <iostream>

#include "Game.h"

#include <Windows.h>

using namespace std;

int main(int argc, char* argv[])
{
	system("color 04"); // RED DISPLAY!
	Game::get_instance()->play();
	return 0;
}

