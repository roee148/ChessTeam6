#include "Piece.h"

Piece::Piece(char type, bool color)
{
	_type = type;
	_color = color;
}

char Piece::getType() const
{
	return _type;
}

void Piece::setType(char type) const
{
	_type = type;
}

bool Piece::getColor() const
{
	return _color;
}
