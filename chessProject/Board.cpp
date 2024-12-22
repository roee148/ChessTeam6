#include "Board.h"
#define BLACK true
#define WHITE false
#define BOARD_SIZE 8
#include <iostream>

Board::Board()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_board[i][j] = new EmptyPiece();
		}
	}
}
int Board::makeMove(int x1, int y1, int x2, int y2, bool currentPlayer)
{
	if (x1 >= BOARD_SIZE || x2 >= BOARD_SIZE || y1 >= BOARD_SIZE || y2 >= BOARD_SIZE)
	{
		return code::INVALID_INDEXES;
	}

	Piece* source = getPiece(x1, y1);
	Piece* destination = getPiece(x2, y2);

	if (source->isEmpty() ||
		source->getColor() != currentPlayer)
	{
		return code::EMPTY_SOURCE_POINT;
	}
	if (destination->getColor() == currentPlayer)
	{
		return code::OCCUPIED_DEST_POINT;
	}
	if (x1 == x2 && y1 == y2)
	{
		return code::SRC_AND_DST_SAME;
	}
	if (!source->isValidMovement(*destination, _board))
	{
		return code::INVALID_MOVEMENT;
	}
	// TODO : move the piece
	updateBoard(source, destination); // todo: this deletes the destination, 
	if (isCheck(source->getColor()))
	{
		// to do : move the piece back
		return code::CHECK_ON_CURRENT_PLAYER;
	}
	if (isCheck(destination->getColor()))
	{
		return code::CHECK;
	}
	// todo: CHECKMATE?
	return code::VALID;
}

void Board::printBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << getPiece(i, j)->getType();
		}
		std::cout << std::endl;
	}
}

void Board::updateBoard(Piece* source, Piece* destination)
{
	int srcX = source->getX();
	int srcY = source->getY();
	int destX = destination->getX();
	int destY = destination->getY();
	delete destination;

	source->setPoint(destX, destY);
	_board[destX][destY] = source;
	_board[srcX][srcX] = new EmptyPiece(srcX, srcY); // todo check
}

Piece* Board::getPiece(int x, int y) const
{
	return _board[x][y];
}

bool Board::isCheck(bool color) const
{
	Piece* king = locateKing(color);

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			Piece* currPiece = _board[i][j];
			if (color != currPiece->getColor() &&
				currPiece->isValidMovement(*king, _board))
			{
				return true;
			}
		}
	}
	return false;
}

Piece* Board::locateKing(bool color) const
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			Piece* tmpPiece = _board[i][j];
			if (tmpPiece->isKing() && color == tmpPiece->getColor())
			{
				return tmpPiece;
			}
		}
	}
}

