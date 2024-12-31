#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
class Queen : public Piece
{
public:
	Queen(int x, int y, bool color) : Piece(x, y, 'q', color) {}
	bool isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const override;
};