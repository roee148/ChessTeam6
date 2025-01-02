#include "Board.h"
#include "EmptyPiece.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Defines.h"

#include <iostream>

Board::Board()
	: _board(BOARD_SIZE, std::vector<Piece*>(BOARD_SIZE, nullptr))
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

Board::~Board()
{
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			delete _board[i][j];
		}
	}
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
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		_board[line][i] = new Pawn(line, i, color);
	}
}

TurnResult Board::makeMove(int rowSrc, int colSrc, int rowDest, int colDest, bool currentPlayer)
{
	Piece* source = getPiece(rowSrc, colSrc);
	Piece* destination = getPiece(rowDest, colDest);

	// source point is empty/not the turn of the current player
	if (source->isEmpty() ||
		source->getColor() != currentPlayer)
	{
		return TurnResult::EMPTY_SOURCE_POINT;
	}

	// dest piece is the same color as the source and is not empty (empty might have the same color)
	if (destination->getColor() == currentPlayer && !destination->isEmpty())
	{
		return TurnResult::OCCUPIED_DEST_POINT;
	}

	// points are identical
	if (rowSrc == rowDest && colSrc == colDest)
	{
		return TurnResult::SRC_AND_DST_SAME;
	}
	
	// the movement is not valid
	if (!source->isValidMovement(*destination, _board))
	{
		return TurnResult::INVALID_MOVEMENT;
	}
	
	// make a move, check if check on myself, if yes move back
	if (!tryMoveAndCheck(source, destination))
	{
		return TurnResult::CHECK_ON_CURRENT_PLAYER;
	}

	// is check on opponent
	if (isCheck(!source->getColor())) 
	{
		return TurnResult::CHECK;
	}

	//if there wasn't any error, the move is valid
	return TurnResult::VALID;
}

void Board::printBoard() const
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
	int srcRow = source->getRow();
	int srcCol = source->getCol();
	int destRow = destination->getRow();
	int destCol = destination->getCol();

	source->setPosition(destRow, destCol);
	_board[destRow][destCol] = source;
	_board[srcRow][srcCol] = new EmptyPiece(srcRow, srcCol);
}


bool Board::tryMoveAndCheck(Piece* source, Piece* destination) 
{
	int srcRow = source->getRow();
	int srcCol = source->getCol();
	int destRow = destination->getRow();
	int destCol = destination->getCol();

	updateBoard(source, destination);

	if (isCheck(source->getColor()))
	{
		// Restore the board
		source->setPosition(srcRow, srcCol);
		delete _board[srcRow][srcCol]; // delete EmptyPiece
		_board[srcRow][srcCol] = source;
		destination->setPosition(destRow, destCol);
		_board[destRow][destCol] = destination;
		return false;
	}
	// movement is valid
	delete destination;
	return true;
}

Piece* Board::getPiece(int row, int col) const
{
	return _board[row][col];
}

bool Board::isCheck(bool color) const
{
	Piece* king = locateKing(color);
	
	// run through all the board pieces
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			Piece* currPiece = _board[i][j];
			//if the current piece is the opponent's piece and it can move to the king there's a check
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
	// run through all the board pieces
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			// if the current piece is a king and its the same color as the color we got
			Piece* tmpPiece = _board[i][j];
			if (tmpPiece->isKing() && color == tmpPiece->getColor())
			{
				return tmpPiece;
			}
		}
	}
	return nullptr;
}

