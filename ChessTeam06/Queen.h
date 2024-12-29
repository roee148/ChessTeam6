#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
class Queen : public Piece,Rook,Bishop
{
public:
	Queen(int x, int y, bool color) : Piece(x, y, 'q', color), Rook(x, y, color), Bishop(x, y, color) {}
	bool virtual isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const;
};