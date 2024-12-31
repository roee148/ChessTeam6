#pragma once
#include <string>
#define BLACK true
#define WHITE false

class Game
{
public:
	int* parseMsg(std::string msg);
	void playGame();
	bool getCurrentPlayer() const;
	void switchTurns();

private:
	bool _currentPlayer = WHITE; // white always starts
};