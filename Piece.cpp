#include "Piece.h"

/**
* Piece representation matrix
* Dimensions/indexes are:
*
* piece type - maximum of 7
* piece rotation - maximum of 4
* row in piece representation
* column in piece representaion
* 1 means filled, 0 means not filled
*/
int repr[PIECE_NUMBER][ROTATION_NUMBER][PIECE_SIZE][PIECE_SIZE] =
{
	// L
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 1, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},

	// Z
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},

	// I
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 1 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 1, 1, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},

	// Square
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},

	// T
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},

	// inverted L
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 1, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},

	// inverted Z
	{
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		}
	},
};

/* Default starting coordinates for each piece */
int defaultX[7] = { 3, 3, 3, 3, 3, 3, 3 };
int defaultY[7] = { -2, -2, -1, -2, -2, -1, -2 };

/* Constructor, nothing to do */
Piece::Piece() {};

/**
* 1-parameter constructor, creates a piece of the given type
* at the default coordinates
*
* @param  piece type
*/
Piece::Piece(int type) {
	this->type = type;
	x = defaultX[type];
	y = defaultY[type];
	rotation = 0;
	moving = 1;
}

/**
* 3-parameter constructor, creates a piece of the given type
* at x and y coordinates
*
* @param Piece type
* @param piece x coordinate
* @param piece y coordinate
*/
Piece::Piece(int type, int x, int y) {
	this->type = type;
	this->x = x;
	this->y = y;
	rotation = 0;
	moving = 1;
}

/* Destructor, nothing to do */
Piece::~Piece() {};

/**
* Getter, returns piece type
*
* @return piece type
*/
int Piece::get_type() {
	return type;
}

/**
* Getter, returns piece current rotation
*
* @return piece current rotation
*/
int Piece::get_rotation() {
	return rotation;
}

/**
* Rotates the piece
*/
void Piece::rotate() {
	if (rotation == 3)
		rotation = 0;
	else
		rotation++;
}

/**
* Switches piece state: moving or not
*/
void Piece::switch_state() {
	if (moving)
		moving = 0;
	else
		moving = 1;
}

/**
* Gets block type in internal representaion at given displacements
*
* @param x displacement
* @param y displacement
* @return block type - 0 for empty, 1 for full
*/
int Piece::filled(int deplX, int deplY) {
	return repr[type][rotation][deplX][deplY];
}

/**
* Getter, returns piece x coordinate
*
* @return piece x coordinate
*/
int Piece::getX() {
	return x;
}

/**
* Getter, returns piece y coordinate
*
* @return piece y coordinate
*/
int Piece::getY() {
	return y;
}

/**
* Adjusts the piece's coordinates according to the direction given
*
* @param direction to move piece to
*/
void Piece::move(int direction) {
	if (direction == UP)
		--x;
	else if (direction == DOWN)
		++x;
	else if (direction == RIGHT)
		++y;
}