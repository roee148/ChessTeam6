#include "King.h"
#include <math.h>
#define BOARD_SIZE 8



bool King::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
	return abs(getX() - dest.getX()) > 1 ||
		   abs(getY() - dest.getY()) > 1;
}




