#pragma once
#include "Piece.h"
class King : Piece
{
public:
	
	code checkMove(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const;
	
private:
	Point _source;
	Point _destination;
};
