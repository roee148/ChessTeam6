#pragma once
#include "Piece.h"
class King : Piece
{
public:
	
	King(int x, int y, char type, bool color) : Piece(x, y, type, color) 
	{
		if (color)
		{
			_type = 'K';
		}
		else
		{
			_type = 'k';
		}
	}

	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override;

};
