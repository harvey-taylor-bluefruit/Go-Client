#include "Go Rules.h"

Rules::Rules(GoBoard &goBoard):
	currentBoard(goBoard.ReturnGoBoardBoard())
{
	
}

void Rules::killthedead(GoBoard &goBoard)
{
	currentBoard = goBoard.ReturnGoBoardBoard();
	for (uint8_t x = 0; x < currentBoard.size(); ++x)
	{
		for (uint8_t y = 0; y < currentBoard.size(); ++y)
		{
			if (checkliberties(x, y) == 0)
			{
				goBoard.PlayStone(x, y, empty);
				currentBoard = goBoard.ReturnGoBoardBoard();
			}
		}
	}
}

uint8_t Rules::checkLibertiesOfAGroup(uint8_t x, uint8_t y)
{
	return 0;
}


uint8_t Rules::checkliberties(uint8_t y, uint8_t x)
{
	uint8_t liberties = 0;
	if (x < currentBoard.size()-1)
		if (currentBoard[x + 1][y] == empty)
			++liberties;
	if (y < currentBoard.size()-1)
		if (currentBoard[x][y + 1] == empty)
			++liberties;
	if (x)
		if (currentBoard[x - 1][y] == empty)
			++liberties;
	if (y)
		if (currentBoard[x][y - 1] == empty)
			++liberties;
	return liberties;
}