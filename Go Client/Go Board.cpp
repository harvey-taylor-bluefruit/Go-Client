#include "Go Board.h"

using namespace std;

GoBoard::GoBoard(uint8_t goBoardSize) :
goBoardSize(goBoardSize), goBoard(CreateGoBoard()),
turn(stone::black), notTurn(stone::white),
deadBlackStones(0), deadWhiteStones(0)
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
			tempGoBoardBoard[x].push_back(stone::empty);
		}
	}
	return tempGoBoardBoard;
}

board GoBoard::ReturnGoBoard()
{
	return goBoard;
}

bool GoBoard::PlayStone(uint8_t X, uint8_t Y, stone stoneColour)
{
	if (goBoard[Y][X] != stone::empty && stoneColour != stone::empty)
		return false;
	goBoard[Y][X] = stoneColour;
	if (stoneColour == stone::white)
	{
		turn = stone::black;
		notTurn = stone::white;
	}
	if (stoneColour == stone::black)
	{
		turn = stone::white;
		notTurn = stone::black;
	}
	return true;
}

stone GoBoard::ReturnWhosMoveIsNext()
{
	return turn;
}

stone GoBoard::ReturnWhosMoveJustWent()
{
	return notTurn;
}

uint16_t GoBoard::ReturnDeadStones(stone stone)
{
	switch (stone)
	{
	case stone::white:
		return deadWhiteStones;
	case stone::black:
		return deadBlackStones;
	}
}

void GoBoard::IncrementDeadStones(stone stone)
{
	switch (stone)
	{
	case stone::white:
		deadWhiteStones++;
	case stone::black:
		deadBlackStones++;
	}
}