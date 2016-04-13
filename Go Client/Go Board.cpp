#include "Go Board.h"

using namespace std;

GoBoard::GoBoard(uint8_t goBoardSize) :
goBoardSize(goBoardSize), goBoardBoard(CreateGoBoard()), turn(stone::BLACK), notTurn(stone::WHITE)
{
}

uint8_t GoBoard::ReturnGoBoardSize()
{
	return goBoardSize;
}

board GoBoard::CreateGoBoard()
{
	board tempGoBoardBoard;
	for (uint8_t x = 0; x < goBoardSize; x++)
	{
		tempGoBoardBoard.push_back(vector<stone> {});
		for (uint8_t y = 0; y < goBoardSize; y++)
		{
			tempGoBoardBoard[x].push_back(stone::EMPTY);
		}
	}
	return tempGoBoardBoard;
}

board GoBoard::ReturnGoBoard()
{
	return goBoardBoard;
}

bool GoBoard::PlayStone(uint8_t X, uint8_t Y, stone stoneColour)
{
	if (goBoardBoard[Y][X] != stone::EMPTY && stoneColour != stone::EMPTY)
		return false;
	goBoardBoard[Y][X] = stoneColour;
	if (stoneColour == stone::WHITE)
	{
		turn = stone::BLACK;
		notTurn = stone::WHITE;
	}
	if (stoneColour == stone::BLACK)
	{
		turn = stone::WHITE;
		notTurn = stone::BLACK;
	}
	return true;
}

stone GoBoard::ReturnTurn()
{
	return turn;
}

stone GoBoard::ReturnNotTurn()
{
	return notTurn;
}