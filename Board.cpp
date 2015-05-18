#include "Board.h"

/** Constructor
* initializes internal board represantations, also sets middle and needs_piece 
*/
Board::Board() {
	content.resize(BOARD_HEIGHT);
	middle = BOARD_WIDTH - 6;
	needs_piece = true;
	score = 0;

	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			if (!i || i == BOARD_HEIGHT - 1 || j == middle)
				content[i].push_back(EDGE);
			else
				content[i].push_back(CLEAR);
		}
	}
}

/* Destructor, nothing to do */
Board::~Board() {};

/**
* Outputs the board on the screen, using
* 'X' for edge
* '@' for pieces which already landed
* '*' for current falling piece
* ' ' for free space
* Draws it top-left or top-right, according to given paramter
* @param Board orientation - DOWN for top-right, UP for top-left
*/
void Board::draw(int type) {
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		// iterates in ascending order for UP and descending for DOWN
		int j;
		if (type == DOWN)
			j = BOARD_WIDTH - 1;
		else if (type == UP)
			j = 0;

		while ((type == DOWN && j >= 0) ||
			(type == UP && j < BOARD_WIDTH)) {
			int currX = curr_piece.getX();
			int currY = curr_piece.getY();

			// we are now within the falling piece's boundaries
			// draw board accordingly
			if (i >= currX &&
				i < currX + 5 &&
				j >= currY &&
				j < currY + 5) {
				if (curr_piece.filled(i - currX, j - currY))
					cout << "*";
				else if (content[i][j] == EDGE)
					cout << 'X';
				else if (content[i][j] == CLEAR)
					cout << ' ';
				else if (content[i][j] == USED)
					cout << '@';
			}
			else {
				if (content[i][j] == EDGE)
					cout << 'X';
				else if (content[i][j] == CLEAR)
					cout << ' ';
				else
					cout << '@';
			}

			// newline
			if (type == DOWN) {
				if (j == 0)
					cout << '\n';
				j--;
			}
			else if (type == UP) {
				if (j == BOARD_WIDTH - 1)
					cout << '\n';
				j++;
			}
		}
	}
}

/**
* Outputs the board on the screen, next to another board
* 'X' for edge
* '@' for pieces which already landed
* '*' for current falling piece
* ' ' for free space
* 
* @param board which needs to be printed next to this one
*/
void Board::draw(Board* b) {
	for (int i = 0; i < BOARD_HEIGHT; i++) {

		// iterate through first board
		for (int j = 0; j < middle; j++) {
			int currX = curr_piece.getX();
			int currY = curr_piece.getY();

			// we are now within the falling piece's boundaries
			// draw board accordingly
			if (i >= currX &&
				i < currX + 5 &&
				j >= currY &&
				j < currY + 5) {
				if (curr_piece.filled(i - currX, j - currY))
					cout << "*";
				else if (content[i][j] == EDGE)
					cout << 'X';
				else if (content[i][j] == CLEAR)
					cout << ' ';
				else if (content[i][j] == USED)
					cout << '@';
			}
			else {
				if (content[i][j] == EDGE)
					cout << 'X';
				else if (content[i][j] == CLEAR)
					cout << ' ';
				else
					cout << '@';
			}
		}
			// iterate through second board
		for (int j = b->get_middle(); j >= 0; j--) {
			Piece crr = b->get_curr_piece();

			int currX = crr.getX();
			int currY = crr.getY();

			if (i >= currX &&
				i < currX + 5 &&
				j >= currY &&
				j < currY + 5) {
				if (crr.filled(i - currX, j - currY))
					cout << "*";
				else if (b->get_content(i, j) == EDGE)
					cout << 'X';
				else if (b->get_content(i, j) == CLEAR)
					cout << ' ';
				else if (b->get_content(i, j) == USED)
					cout << '@';
			}
			else {
				if (b->get_content(i, j) == EDGE)
					cout << 'X';
				else if (b->get_content(i, j) == CLEAR)
					cout << ' ';
				else
					cout << '@';
			}

			// newline
			if (j == 0)
				cout << '\n';
		}
	}
}

/**
* Adjusts middle of the board to the direction given
*
* @param  direction given - UP for up and DOWN for down
*/
void Board::adjust_middle(int side) {
	if (side == DOWN) {
		// cant'move lower than that
		if (middle == BOARD_WIDTH - 1)
			return;
		for (int i = 1; i < BOARD_HEIGHT; i++)
		{
			content[i][middle + 1] = EDGE;
		}
		delete_line(middle);
		++middle;
	}

	if (side == UP) {
		// can't move higher than that
		if (middle == 1)
			return;

		// kind of a reversed delete_line, shift towards top instead
		for (int i = 0; i < middle; i++)
			for (int j = 1; j < BOARD_HEIGHT - 1; j++)
				content[j][i] = content[j][i + 1];
		for (int i = 1; i < BOARD_HEIGHT - 1; i++)
			content[i][middle] = CLEAR;
		--middle;
	}
}

/**
* Adds a piece to the internal represantation of the board
* Called when a piece has fallen completely
*
* @param  piece to add
*/
void Board::add_piece(Piece p) {
	// cannot add a piece if there is a collision
	if (is_collision(p)) {
		return;
	}

	for (int i = 0; i < PIECE_SIZE; i++)
		for (int j = 0; j < PIECE_SIZE; j++)
			if (p.filled(i, j))
				content[p.getX() + i][p.getY() + j] = USED;
}

/**
* Checks if location of the given piece collides with existent blocks
* be them previous pieces or board edges
*
* @param  piece to check for
* @return true if there is a collision, false otherwise
*/
bool Board::is_collision(Piece p) {
	for (int i = 0; i < PIECE_SIZE; i++)
		for (int j = 0; j < PIECE_SIZE; j++) {
			int posX = p.getX() + i;
			int posY = p.getY() + j;

			if (p.filled(i, j) && (
				posX < 0 ||
				posY < 0 ||
				posX >= BOARD_HEIGHT ||
				posY >= BOARD_WIDTH)) {
				return true;
			}

			if (p.filled(i, j) && content[posX][posY] != CLEAR) {
				return true;
			}
		}
	return false;
}

/**
* Setter, sets board current piece to given parameter
*
* @param  piece to set as current
*/
void Board::set_curr_piece(Piece p) {
	curr_piece = p;
	needs_piece = false;
}

/**
* Getter, returns board's current falling piece
*
* @return current falling piece
*/
Piece Board::get_curr_piece() {
	return curr_piece;
}

/**
* Checks to see if any lines are complete
* If there are, delete them, also increase the score accordingly
*
* @return number of lines deleted
*/
int Board::delete_needed_lines() {
	int ret = 0;
	for (int i = 0; i < middle; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			if (content[j][i] == CLEAR) break;
			if (j == BOARD_HEIGHT - 1) {
				delete_line(i);
				++score;
				++ret;
			}
		}
	}
	return ret;
}

/**
* Deletes the line given
* Shifts all the content above it one step below
*
* @param line to be deleted
*/
void Board::delete_line(int line) {

	for (int i = line; i > 0; i--)
		for (int j = 1; j < BOARD_HEIGHT - 1; j++)
			content[j][i] = content[j][i - 1];

	// also set first line as clear
	for (int i = 1; i < BOARD_HEIGHT - 1; i++)
		content[i][0] = CLEAR;
}

/**
* Moves the current piece to the desired direction
* Also receives an id, which means the player for
* which the piece needs to be moved
*
* @param character pressed
* @param id of the player whose board needs to be moved
*/
void Board::move_curr_piece(char move, int id) {
	Piece next_piece = curr_piece;

		// move up
		if ((id == 1 && move == 'w') ||
			(id == 2 && move == 'i')) {
			next_piece.move(UP);
			if (!is_collision(next_piece))
				set_curr_piece(next_piece);
		}
		// move down
		else if ((id == 1 && move == 's') ||
				(id == 2 && move == 'k')) {
			next_piece.move(DOWN);
			if (!is_collision(next_piece))
				set_curr_piece(next_piece);
		}
		// rotate
		else if ((id == 1 && move == 'a') ||
				(id == 2 && move == 'j')) {
			next_piece.rotate();
			if (!is_collision(next_piece))
				set_curr_piece(next_piece);
		}
}

/**
* Getter, returns board's current score
*
* @return current score
*/
int Board::get_score() {
	return score;
}

/**
* Getter, returns board's content at positions x and y
*
* @param ordinate of deisred location
* @param abscissa of desired location
* @return board content at cooridnates x and y
*/
int Board::get_content(int x, int y) {
	return content[x][y];
}

/**
* Getter, returns board's current middle location
*
* @return current middle location
*/
int Board::get_middle() {
	return middle;
}
