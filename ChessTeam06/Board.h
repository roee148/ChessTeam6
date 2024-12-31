#pragma once
#include <iostream>
#include <vector>
#include "Piece.h"

class Board
{
public:
	Board();
	code makeMove(int rowSrc, int colSrc, int rowDest, int colDest, bool currentPlayer);
	void printBoard();
	
private:

	//helper
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