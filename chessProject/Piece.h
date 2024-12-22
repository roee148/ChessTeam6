#pragma once
#include "point.h"
#include "Board.h"
#include <vector>

class Piece
{
protected:
	char _type;
	bool _color;
	Point _point;

public:
	// Constructors
	Piece(int x, int y, char type, bool color);

	// Getters
	char getType() const;
	bool getColor() const;
	int getX() const;
	int getY() const;
	bool isEmpty() const;
	void setPoint(int x, int y);


	// Methods	
	bool virtual isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const = 0;
	bool isKing() const;

protected:
	void setType(char type);

};

enum code
{
	VALID,
	CHECK,
	EMPTY_SOURCE_POINT,
	OCCUPIED_DEST_POINT,
	CHECK_ON_CURRENT_PLAYER,
	INVALID_INDEXES,
	INVALID_MOVEMENT,
	SRC_AND_DST_SAME,
	CHECKMATE
};