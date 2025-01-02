#include <iostream>
#include "Piece.h"

Piece::Piece(int row, int col, char type, bool color): _row(row), _col(col), _color(color)
{
	setType(type);
}

char Piece::getType() const
{
	return _type;
}

void Piece::setType(char type)
{
	if (_color == BLACK) // if the color is black, lower the char
	{
		_type = (char)tolower(type);
	}
	else // if the color is white, uppers the char
	{
		_type = (char)toupper(type);
	}
}

bool Piece::getColor() const
{
	return _color;
}

int Piece::getCol() const
{
	return _col;
}

int Piece::getRow() const
{
	return _row;
}

bool Piece::isEmpty() const
{
	return false;
}

void Piece::setPosition(int row, int col)
{
	_row = row;
	_col = col;
}
 
bool Piece::isKing() const
{
	return false;
}
