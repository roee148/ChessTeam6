#include "King.h"
#include <math.h>

code King::checkMove(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const
{
	if (abs(getX() - dest.getX()) > 1 ||
		abs(getY() - dest.getY()) > 1)
	{
		return code::INVALID_MOVEMENT;
	}




}



