#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:

	Pawn(int row, int col, bool color) : Piece(row, col, 'p', color) {}

	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override;

private:
	bool _isFirstTurn = true;
};

