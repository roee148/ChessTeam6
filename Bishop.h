#pragma once
#include "Piece.h"
class Bishop : Piece
{
public:
	Bishop(int x, int y, bool color) : Piece(x, y, 'b', color) {}
	bool virtual isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const;
};