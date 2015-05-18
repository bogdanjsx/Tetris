#pragma once

#include "Piece.h"

#include <vector>

using namespace std;

#define BOARD_HEIGHT 12
#define BOARD_WIDTH 41

// representaion types
#define EDGE (-1)
#define CLEAR 0
#define USED 1

class Board {
public:
	Board();
	virtual ~Board();

	void draw(int type);
	void draw(Board* b);
	void adjust_middle(int side);
	void add_piece(Piece p);
	bool is_collision(Piece p);
	void set_curr_piece(Piece p);
	int delete_needed_lines();
	Piece get_curr_piece();
	void move_curr_piece(char move, int id);
	int get_score();
	int get_middle();
	int get_content(int x, int y);

	bool needs_piece; // flag to see if another falling piece needs to be inserted

private:
	vector<vector<int> > content; // internal representation
	int middle; // current middle position
	Piece curr_piece; // current falling piece
	int score; // number of deleted lines
	void delete_line(int line); 
};