#pragma once
#include "point.h"
#include <vector>

class Piece
{
protected:
	char _type;
	bool _color;
	int _row;
	int _col;

public:
	// Constructors
	Piece(int row, int col, char type, bool color);

	// Getters
	char getType() const;
	bool getColor() const;
	int getCol() const;
	int getRow() const;
	void setPosition(int row, int col);


	// Methods	
	bool virtual isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const = 0;
	bool virtual isKing() const;
	bool virtual isEmpty() const;

protected:
	void setType(char type);

};

enum code
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