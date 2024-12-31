#include "Board.h"
#include "EmptyPiece.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#define BLACK true
#define WHITE false
#define BOARD_SIZE 8
#include <iostream>

Board::Board()
	: _board(8, std::vector<Piece*>(8, nullptr))
{ 
	//set white pieces
	setPieces(0, WHITE);

	//set white pawns
	setPawns(1, WHITE);
	
	//set empty pieces
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_board[i][j] = new EmptyPiece(i, j);
		}
	}

	//set black pawns
	setPawns(6, BLACK);

	//set black pieces
	setPieces(7, BLACK);

}

void Board::setPieces(int line, bool color)
{
	_board[line][0] = new Rook(line, 0, color);
	_board[line][1] = new Knight(line, 1, color);
	_board[line][2] = new Bishop(line, 2, color);
	_board[line][3] = new King(line, 3, color);
	_board[line][4] = new Queen(line, 4, color);
	_board[line][5] = new Bishop(line, 5, color);
	_board[line][6] = new Knight(line, 6, color);
	_board[line][7] = new Rook(line, 7, color);
}

void Board::setPawns(int line, bool color)
{
	_board[line][0] = new Pawn(line, 0, color);
	_board[line][1] = new Pawn(line, 1, color);
	_board[line][2] = new Pawn(line, 2, color);
	_board[line][3] = new Pawn(line, 3, color);
	_board[line][4] = new Pawn(line, 4, color);
	_board[line][5] = new Pawn(line, 5, color);
	_board[line][6] = new Pawn(line, 6, color);
	_board[line][7] = new Pawn(line, 7, color);
}

code Board::makeMove(int x1, int y1, int x2, int y2, bool currentPlayer)
{
	/*if (x1 >= BOARD_SIZE || x2 >= BOARD_SIZE || y1 >= BOARD_SIZE || y2 >= BOARD_SIZE)
	{
		return code::INVALID_INDEXES;
	}*/

	Piece* source = getPiece(x1, y1);
	Piece* destination = getPiece(x2, y2);

	// if the source point is empty/not the turn of the current player
	if (source->isEmpty() ||
		source->getColor() != currentPlayer)
	{
		return code::EMPTY_SOURCE_POINT;
	}

	//if the dest piece is the same as the source and is not empty (empty might have the same color)
	if (destination->getColor() == currentPlayer && !destination->isEmpty())
	{
		return code::OCCUPIED_DEST_POINT;
	}

	//if the point are identical (can't happen on frontend)
	if (x1 == x2 && y1 == y2)
	{
		return code::SRC_AND_DST_SAME;
	}
	
	//if the movement is not valid

	if (!source->isValidMovement(*destination, _board))
	{
		return code::INVALID_MOVEMENT;
	}
	
	if (!tryMoveAndCheck(source, destination)) // make a move, check if check on myself, is yes move back
	{
		return code::CHECK_ON_CURRENT_PLAYER;
	}

	if (isCheck(!source->getColor())) // is check on opponent
	{
		return code::CHECK;
	}

	return code::VALID;
}

void Board::printBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << getPiece(i, j)->getType() << " ";
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

	source->setPoint(destX, destY);
	_board[destX][destY] = source;
	_board[srcX][srcY] = new EmptyPiece(srcX, srcY);
}


bool Board::tryMoveAndCheck(Piece* source, Piece* destination) 
{
	int srcX = source->getX();
	int srcY = source->getY();
	int destX = destination->getX();
	int destY = destination->getY();

	updateBoard(source, destination);

	if (isCheck(destination->getColor()))
	{
		// Restore the board
		source->setPoint(srcX, srcY);
		delete _board[srcX][srcY]; // delete EmptyPiece
		_board[srcX][srcY] = source;
		destination->setPoint(destX, destY);
		_board[destX][destY] = destination;
		return false;
	}
	// movement is valid
	delete destination;
	return true;
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
	return nullptr;
}

