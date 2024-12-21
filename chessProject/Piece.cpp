#include "Piece.h"
#define EMPTY '#'
#define BOARD_SIZE 8

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
 
Piece* Piece::locateKing(const std::vector<std::vector<Piece*>>& board, bool color)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			Piece* tmpPiece = board[i][j];
			if (tmpPiece->isKing() && color == tmpPiece->getColor())
			{
				return tmpPiece;
			}
		}
	}
}

bool Piece::isKing() const
{
	return (char)tolower(_type) == 'k';
}

bool Piece::getColor() const
{
	return _color;
}

bool Piece::isCheckOnCurrentPlayer(const std::vector<std::vector<Piece*>>& board) const
{
	return isCheck(board, _color);
}

bool Piece::isCheckOnOpponent(const std::vector<std::vector<Piece*>>& board) const
{
	return isCheck(board, !_color);
}

bool Piece::isCheck(const std::vector<std::vector<Piece*>>& board, bool color)
{
	Piece* king = locateKing(board, color);

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			Piece* currPiece = board[i][j];
			if (color != currPiece->getColor() &&
				currPiece->isValidMovement(*king, board))
			{
				return true;
			}
		}
	}
	return false;
}


