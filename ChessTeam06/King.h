#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	
	King(int row, int col, bool color) : Piece(row, col, 'k', color) {}

	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override;
	bool isKing() const;
};
