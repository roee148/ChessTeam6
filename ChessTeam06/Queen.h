#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
class Queen : public Piece
{
public:
	Queen(int row, int col, bool color) : Piece(row, col, 'q', color) {}
	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override;
};