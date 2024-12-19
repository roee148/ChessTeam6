#pragma once
#include "point.h"

class Piece
{
private:
	char _type;
	bool _color;

public:
	// Constructors
	Piece(char type, bool color);


	// Getters
	char getType() const;
	void setType(char type) const;
	bool getColor() const;

	// Methods
	code virtual isValidMove(Point p , bool) const = 0;

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