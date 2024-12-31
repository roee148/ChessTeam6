#pragma once
#include "Piece.h"
class EmptyPiece : public Piece
{
public:

	EmptyPiece(int row, int col) : Piece(row, col, '#', false) {} // color doesnt matter

	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override { return false; }
	bool isEmpty() const override { return true; }
};

