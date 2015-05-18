#include "Game.h"

Game* Game::instance = nullptr; // shared instance initialization

/**
* Getter, returns shared instance of class
* Creates it if function is called for the first time
*
* @return shared instance
*/
Game* Game::get_instance() {
	if (instance == nullptr)
		instance = new Game;

	return instance;
}

/**
* Main game cycle, handles user interaction and checks if game is over
*/
void Game::play() {

	// run indefinitely
	while (1) {
		auto b1 = new Board();
		auto b2 = new Board();
		srand(time(NULL)); //random seed set as current time

		int game_over = 0;
		int winner;

		while (!game_over) {
			display_help();
			display_score(b1, b2);

			// if any board needs a piece, add it
			if (b1->needs_piece) {
				int next = rand() % 7;
				Piece new_piece(next);
				if (b1->is_collision(new_piece)) {
					game_over = 1;
					winner = 2;
				}
				b1->set_curr_piece(new_piece);
			}

			if (b2->needs_piece) {
				int next = rand() % 7;
				Piece new_piece(next);
				if (b2->is_collision(new_piece)) {
					game_over = 1;
					winner = 1;
				}
				b2->set_curr_piece(new_piece);
			}

			Piece current1 = b1->get_curr_piece(), potential1;
			Piece current2 = b2->get_curr_piece(), potential2;
			char move;

			// draw boards
			b1->draw(b2);

			move = wait_for_char(WAIT_TIME); // wait for input

			// quit immediatly
			if (move == 'q') {
				winner = 1;
				break;
			}

			if (move == 'w') {
				current1.move(UP);
				if (!b1->is_collision(current1))
					b1->set_curr_piece(current1);
				continue;
			}
			else if (move == 's') {
				current1.move(DOWN);
				if (!b1->is_collision(current1))
					b1->set_curr_piece(current1);
				continue;
			}
			else if (move == 'a') {
				current1.rotate();
				if (!b1->is_collision(current1))
					b1->set_curr_piece(current1);
				continue;
			}

			else if (move == 'i') {
				current2.move(UP);
				if (!b2->is_collision(current2))
					b2->set_curr_piece(current2);
				continue;
			}
			else if (move == 'k') {
				current2.move(DOWN);
				if (!b2->is_collision(current2))
					b2->set_curr_piece(current2);
				continue;
			}
			else if (move == 'l') {
				current2.rotate();
				if (!b2->is_collision(current2))
					b2->set_curr_piece(current2);
				continue;
			}

			// check if current piece of the boards has completely fallen
			potential1 = current1;
			potential2 = current2;


			potential1.move(RIGHT);
			if (!b1->is_collision(potential1))
				b1->set_curr_piece(potential1);
			else {
				b1->add_piece(current1);
				b1->needs_piece = true;
			}

			potential2.move(RIGHT);
			if (!b2->is_collision(potential2))
				b2->set_curr_piece(potential2);
			else {
				b2->add_piece(current2);
				b2->needs_piece = true;
			}

			int adjust1 = b1->delete_needed_lines();
			int adjust2 = b2->delete_needed_lines();

			// for each deleted line adjust the base of the boards accordingly 
			for (int i = 0; i < adjust1; i++)
			{
				b1->adjust_middle(DOWN);
				b2->adjust_middle(UP);
			}

			for (int i = 0; i < adjust2; i++)
			{
				b2->adjust_middle(DOWN);
				b1->adjust_middle(UP);
			}
		}

		// ask for input, if input is 'y' start another game
		cout << "\nPlayer " << winner << " WINS!\n\n";
		cout << "Play again? (Y or N)\n";
		char resume = getch();
		if (resume == 'n')
			break;

	}
}