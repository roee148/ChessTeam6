#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight(int x, int y, bool color) : Piece(x, y, 'n', color) {}
	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override;;
};