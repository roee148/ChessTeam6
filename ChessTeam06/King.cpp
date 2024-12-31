#include "King.h"
#include <math.h>

bool King::isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
	//the king can move 1 square at a time at any direction
	bool isInValidMovement = abs(getCol() - dest.getCol()) > 1 ||
							 abs(getRow() - dest.getRow()) > 1;
	return !isInValidMovement;
}

bool King::isKing() const
{
	return true;
}