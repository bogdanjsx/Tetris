#include "Helper.h"

/**
* Waits for input for milis miliseconds
* If any key was pressed, return that key, else return 0
*
* @param  Time to wait in miliseconds
* @return Key which was pressed
*/
char wait_for_char(int milis) {
	while (1) {
		if (_kbhit()){
			char c = _getch();
			return c;
		}

		Sleep(10);
		milis -= 10;

		if (milis == 0)
			return '\0';
	}
}

/**
* Displays controls for both players
*/
void display_help() {
	system("CLS");
	cout << "Controls: \n";
	cout << "Player 1 - W to move up, S to move down, A to rotate\n";
	cout << "Player 2 - I to move up, K to move down, L to rotate\n";
	cout << "Q to quit immediately (Player 2 resigns)\n\n";
}

/**
* Displays current score of the 2 boards
*
* @param Player 1's board
* @param Player 2's board
*/
void display_score(Board* b1, Board* b2) {
	cout << "\nSCORE: " << b1->get_score() << " - " << b2->get_score() << "\n\n";

}