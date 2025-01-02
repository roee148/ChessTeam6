#pragma once
#include <string>
#include "Defines.h"

class Game
{
public:
	void playGame();

private:
	bool _currentPlayer = WHITE; // white always starts

	void parseMsg(const std::string& msg, int* coordinates) const;
	bool getCurrentPlayer() const;
	void switchTurns();
};