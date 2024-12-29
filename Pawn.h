#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:

	Pawn(int x, int y, bool color) : Piece(x, y, 'p', color) {}

	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override;

private:
	bool isFirstTurn = true;
};

