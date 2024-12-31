#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(int row, int col, bool color) : Piece(row, col, 'r', color) {}
	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override;
};