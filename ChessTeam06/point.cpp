#include "Point.h"

Point::Point(char x, char y)
{
	_x = x;
	_y = y;
	_piece;
}




char Point::getX() const
{
	return _x;
}

char Point::getY() const
{
	return _y;
}

bool Point::isEmpty() const
{
	if (_piece->getType() == '#')
	{
		return true;
	}
	return false;
}

void Point::capture()
{
	_piece->setType('#');
}

code Point::isValidMove(Point p1, Point p2) const
{
	return _piece.isValidMove(p1, p2);
}

bool Point::getColor() const
{
	return _piece->getColor();
}

