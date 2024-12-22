#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include "Piece.h"

enum code
{
	VALID,
	CHECK,
	EMPTY_SOURCE_POINT, //source point is empty/the piece in the source point is the oponent's piece
	OCCUPIED_DEST_POINT, 
	CHECK_ON_CURRENT_PLAYER,
	INVALID_INDEXES,
	INVALID_MOVEMENT,
	SRC_AND_DST_SAME,
	CHECKMATE
};

class Board
{
	Board();
	int makeMove(int x1, int y1, int x2, int y2, bool color);
	void printBoard();
	void updateBoard(Piece* source, Piece* destination);
	Piece* locateKing(bool color) const;
	bool isCheck(bool color) const;
	

private:
	Piece* getPiece(int x, int y) const;
	std::vector<std::vector<Piece*>> _board;  // 2d vector for the board

};