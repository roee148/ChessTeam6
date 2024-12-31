#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop(int row, int col, bool color) : Piece(row, col, 'b', color) {}
	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override;
};