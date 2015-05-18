#pragma once

#include <iostream>
using namespace std;

#define PIECE_SIZE 5 // internal representaion size
#define PIECE_NUMBER 7 // number of existing pieces
#define ROTATION_NUMBER 4 // number of existing rotations for a piece

// directions to move the piece to
#define RIGHT 0
#define UP 1
#define DOWN 2


class Piece {
public:
	Piece();
	Piece(int type);
	Piece(int type, int x, int y);
	virtual ~Piece();

	int get_type();
	int get_rotation();
	void rotate();
	void switch_state();
	int filled(int deplX, int deplY);
	int getX();
	int getY();
	void move(int direction);

private:
	// coordinates
	int x; 
	int y;
	
	// type and rotation
	int type;
	int rotation;

	// moving state
	bool moving;
};