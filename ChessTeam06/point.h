#pragma once
#include <iostream>

class Point
{
private:
	int _x;
	int _y;

public:
	// Constructor
	Point(int x, int y);
	// Getters
	int getX() const;
	int getY() const;

};