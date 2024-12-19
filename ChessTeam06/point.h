#pragma once
#include <iostream>
#include "Piece.h"



class Point
{
private:
	char _x;
	char _y;
	Piece* _piece;

public:
	// Constructors
	Point(char x, char y);
	// Getters
	char getX() const;
	char getY() const;
	bool getColor() const;
	// Methods
	bool isEmpty() const;
	void capture();
	code isValidMove(Point p1, Point p2) const;
	
};

