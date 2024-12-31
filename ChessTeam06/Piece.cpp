#include "Piece.h"
#define EMPTY '#'
#define BLACK true
#define WHITE false

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
	if (_color == BLACK) // if the color is black (true), lower the char
	{
		_type = (char)tolower(type);
	}
	else // if the color is white (false), uppers the char
	{
		_type = (char)toupper(type);
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
