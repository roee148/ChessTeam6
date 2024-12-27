#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	
	King(int x, int y, bool color) : Piece(x, y, 'k', color) {}

	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override;

};
