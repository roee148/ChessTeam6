#include "Piece.h"
#define EMPTY '#'

Piece::Piece(int x, int y, char type, bool color): _point(Point(x, y)), _color(color)
{}

char Piece::getType() const
{
	return _type;
}

void Piece::setType(char type)
{
	_type = type;
}

bool Piece::getColor() const
{
	return _color;
}

int Piece::getX() const
{
	return _point.getX();
}

int Piece::getY() const
{
	return _point.getY();
}

bool Piece::isEmpty() const
{
	return _type == EMPTY;
}

void Piece::setEmpty()
{
	_type = EMPTY;
}

bool Piece::getColor() const
{
	return _color;
}

