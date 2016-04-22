#include "ConsoleFunctions.h"
#include <iostream>
#include <string>

using namespace ::std;

void ConsoleFuntions::PrintBoard(GoBoard &goBoard)
{
	board currentBoard = goBoard.ReturnGoBoard();
	uint8_t sizeOfCurrentBoard = goBoard.ReturnGoBoardSize();
	for (uint8_t x = 0; x < sizeOfCurrentBoard; x++)
	{
		for (uint8_t y = 0; y < sizeOfCurrentBoard; y++)
		{
			switch (currentBoard[x][y])
			{
			case stone::empty:
				cout << "+ ";
				break;
			case stone::black:
				cout << "O ";
				break;
			case stone::white:
				cout << "0 ";
				break;
			}
		}
		cout << endl;
	}
	ConsoleFuntions::OutputDeadStones(goBoard);
}

void ConsoleFuntions::OutputDeadStones(GoBoard &goBoard)
{
	cout << "Dead white stones : " << goBoard.ReturnDeadStones(stone::white) << endl;
	cout << "Dead black stones : " << goBoard.ReturnDeadStones(stone::black) << endl;
}

void ConsoleFuntions::ObtainValidPlayerMove(GoBoard &goBoard)
{
	while (!GetCoordinatesAndPlay(goBoard))
	{
		std::cout << "you cant go there!" << std::endl;
	}
}

bool ConsoleFuntions::GetCoordinatesAndPlay(GoBoard &goBoard)
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

	return goBoard.PlayStone(x, y, goBoard.ReturnWhosMoveIsNext());
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
		cin >> stringInput;
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
			cout << "Out of range!" << endl;
			cout << message << endl;
			succesfull = false;
		}
	}
	return input;
}