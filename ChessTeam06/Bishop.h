#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop(int x, int y, bool color) : Piece(x, y, 'b', color) {}
	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override;
};