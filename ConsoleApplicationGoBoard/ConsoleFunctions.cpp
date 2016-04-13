#include "ConsoleFunctions.h"
#include <iostream>
#include <string>

using namespace std;

void ConsoleFuntions::PrintBoard(GoBoard &goBoard)
{
	board CurrentBoard = goBoard.ReturnGoBoard();
	uint8_t SizeOfCurrentBoard = goBoard.ReturnGoBoardSize();
	for (uint8_t x = 0; x < SizeOfCurrentBoard; x++)
	{
		for (uint8_t y = 0; y < SizeOfCurrentBoard; y++)
		{
			switch (CurrentBoard[x][y])
			{
			case stone::EMPTY:
				cout << "+ ";
				break;
			case stone::BLACK:
				cout << "O ";
				break;
			case stone::WHITE:
				cout << "0 ";
				break;
			}
		}
		cout << endl;
	}
}

void ConsoleFuntions::playerMove(GoBoard &goBoard)
{
	while (!GetCoordiatesAndPlay(goBoard))
	{
		std::cout << "you cant go there!" << std::endl;
	}
}

bool ConsoleFuntions::GetCoordiatesAndPlay(GoBoard &goBoard)
{
	uint8_t size = goBoard.ReturnGoBoardSize();
	int16_t x = size;
	int16_t y = size;
	while (x >= 0 && x >= size)
	{
		x = GetInput("please input an x coordinate : ");
	}
	while (y >= 0 && y >= size)
	{
		y = GetInput("please input an y coordinate : ");
	}

	return goBoard.PlayStone(x, y, goBoard.ReturnTurn());
}

uint8_t ConsoleFuntions::GetInput(string message)
{
	cout << message << endl;
	string stringInput;
	size_t* pos = 0;
	uint8_t input = 0; 
	uint8_t base = 10;
	bool succesfull = false;
	while (!succesfull)
	{
		cin >> input;
		try
		{
			input = stoi(stringInput, pos, base);
			succesfull = true;
		}
		catch (invalid_argument)
		{
			cout << "Invalid!" << endl;
			cout << message << endl;
			succesfull = false;
		}
		catch (out_of_range)
		{
			cout << "Invalid!" << endl;
			cout << message << endl;
			succesfull = false;
		}
	}
	return input;
}