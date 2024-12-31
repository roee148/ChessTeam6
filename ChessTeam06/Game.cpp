#include "Game.h"
#include "Pipe.h"
#include "Board.h"
#include <string>
#include <iostream>

int* Game::parseMsg(std::string msg)
{
	int* indexes = new int[4]; //the msg built like this: a2a4
	//if char is letter (happens in indexes 0 and 2), subtract 'a' to get int
	//if the char is a number (happens in indexes 1 and 3) subtract '0' to get int

	//chess cordinates to board cordinates
	indexes[0] = msg[0] - 'a';
	indexes[1] = 8 - (msg[1] - '0');
	indexes[2] = msg[2] - 'a';
	indexes[3] = 8 - (msg[3] - '0');

	return indexes;
}

void Game::playGame()
{
	srand(time_t(NULL));
	Pipe p;
	bool isConnect = p.connect();
	std::string ans;

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
			return;
		}
	}

	char msgToGraphics[1024];
	//strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"); // just example...
	strcpy_s(msgToGraphics, "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr0"); // just example...
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	std::string msgFromGraphics = p.getMessageFromGraphics();

	int* coordinates = nullptr;

	Board gameBoard;

	while (msgFromGraphics != "quit")
	{
		gameBoard.printBoard();
		coordinates = parseMsg(msgFromGraphics);
		int colSrc = coordinates[0];
		int rowSrc = coordinates[1];
		int colDest = coordinates[2];
		int rawDest = coordinates[3];
		
		//check the validity of the move
		code returnCode = gameBoard.makeMove(rowSrc, colSrc, rawDest, colDest, _currentPlayer);
		
		//if the move is valid, switch the turn to the other player
		if (returnCode == code::VALID || returnCode == code::CHECK)
		{
			switchTurns();
		}
		
		std::string strCode = std::to_string(returnCode);
		strcpy_s(msgToGraphics, strCode.c_str()); // msgToGraphics should contain the result of the operation
		

		/*
		// JUST FOR EREZ DEBUGGING 
		int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(8 + '0');
		msgToGraphics[1] = 0;
		// JUST FOR EREZ DEBUGGING */


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


