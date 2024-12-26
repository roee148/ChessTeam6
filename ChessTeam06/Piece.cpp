#include "Piece.h"
#define EMPTY '#'

Piece::Piece(int x, int y, char type, bool color): _point(Point(x, y)), _color(color)
{
	setType(type);
}

char Piece::getType() const
{
	return _type;
}

void Piece::setType(char type)
{
	if (_color)
	{
		_type = (char)toupper(type);
	}
	else
	{
		_type = (char)tolower(type);
	}
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

void Piece::setPoint(int x, int y)
{
	_point = Point(x, y);
}
 
bool Piece::isKing() const
{
	return (char)tolower(_type) == 'k';
}
