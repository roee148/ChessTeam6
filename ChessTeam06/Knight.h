#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight(int row, int col, bool color) : Piece(row, col, 'n', color) {}
	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override;;
};