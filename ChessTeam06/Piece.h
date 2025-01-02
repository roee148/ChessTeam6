#pragma once
#include <vector>
#include "Defines.h"

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

	// setters
	void setPosition(int row, int col);

	// Methods	
	bool virtual isValidMovement(const Piece& dest, const std::vector<std::vector<Piece*>>& board) const = 0;
	bool virtual isKing() const;
	bool virtual isEmpty() const;

private:
	void setType(char type);

};