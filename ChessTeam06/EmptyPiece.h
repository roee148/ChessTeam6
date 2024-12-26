#pragma once
#include "Piece.h"
class EmptyPiece : public Piece
{
public:

	EmptyPiece(int x, int y) : Piece(x, y, '#', 0) {} // color doesnt matter

	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override { return false; }

};

