#pragma once
#include <iostream>
#include <vector>
#include "Piece.h"

enum TurnResult
{
	VALID,
	CHECK,
	EMPTY_SOURCE_POINT, //source point is empty/the piece in the source point is the opponent's piece
	OCCUPIED_DEST_POINT,
	CHECK_ON_CURRENT_PLAYER,
	INVALID_INDEXES,
	INVALID_MOVEMENT,
	SRC_AND_DST_SAME,
	CHECKMATE
};

class Board
{
public:
	Board();
	~Board();
	TurnResult makeMove(int rowSrc, int colSrc, int rowDest, int colDest, bool currentPlayer);
	void printBoard() const;
	
private:

	//helpers
	void updateBoard(Piece* source, Piece* destination);
	bool tryMoveAndCheck(Piece* source, Piece* destination);
	Piece* locateKing(bool color) const;
	bool isCheck(bool color) const;
	Piece* getPiece(int row, int col) const;
	void setPieces(int line, bool color);
	void setPawns(int line, bool color);

	//field
	std::vector<std::vector<Piece*>> _board;  // 2d vector for the board
};