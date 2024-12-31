#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(int x, int y, bool color) : Piece(x, y, 'r', color) {}
	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override;
};