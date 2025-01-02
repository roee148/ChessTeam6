#include "Game.h"
#include "Pipe.h"
#include "Board.h"
#include <string>
#include <iostream>

void Game::parseMsg(const std::string& msg, int* coordinates) const
{
	//the msg built like this: a2a4
	//if char is letter (happens in indexes 0 and 2), subtract 'a' to get int
	//if the char is a number (happens in indexes 1 and 3) subtract '0' to get int

	//chess coordinates to board coordinates
	coordinates[0] = msg[0] - 'a';
	coordinates[1] = 8 - (msg[1] - '0');
	coordinates[2] = msg[2] - 'a';
	coordinates[3] = 8 - (msg[3] - '0');
}

static bool connectToGraphics(Pipe& p) {
	srand(time_t(NULL));
	bool isConnect = p.connect();
	std::string ans;

	//connect to frontend
	while (!isConnect)
	{
		std::cout << "cant connect to graphics" << std::endl;
		std::cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << std::endl;
		std::cin >> ans;
		if (ans == "0")
		{
			std::cout << "trying connect again.." << std::endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return false;
		}
	}
	return true;
}

void Game::playGame()
{
	Pipe p;
	if (!connectToGraphics(p))
	{
		return;
	}

	char msgToGraphics[1024];
	
	//starting string
	strcpy_s(msgToGraphics, "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr0");
	p.sendMessageToGraphics(msgToGraphics);

	std::string msgFromGraphics = p.getMessageFromGraphics();

	int coordinates[4];

	Board gameBoard;

	while (msgFromGraphics != "quit")
	{
		gameBoard.printBoard();

		//get the coordinates from the msg from graphics
		parseMsg(msgFromGraphics, coordinates);
		int colSrc = coordinates[0];
		int rowSrc = coordinates[1];
		int colDest = coordinates[2];
		int rawDest = coordinates[3];
		
		//check the validity of the move
		TurnResult returnCode = gameBoard.makeMove(rowSrc, colSrc, rawDest, colDest, _currentPlayer);
		
		//if the move is valid, switch the turn to the other player
		if (returnCode == TurnResult::VALID || returnCode == TurnResult::CHECK)
		{
			switchTurns();
		}
		
		std::string strCode = std::to_string(returnCode);
		strcpy_s(msgToGraphics, strCode.c_str()); // msgToGraphics should contain the result of the operation
		
		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}

bool Game::getCurrentPlayer() const
{
	return _currentPlayer;
}

void Game::switchTurns()
{
	_currentPlayer = !_currentPlayer;
}


