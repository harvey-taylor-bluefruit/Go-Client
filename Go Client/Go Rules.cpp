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
			currentBoard = goBoard.ReturnGoBoardBoard();
			checkedCoordinates = {};
			currentStone = currentBoard[x][y];
			liberties = 0;
			if (checkLibertiesOfAGroup(x, y) == 0 && currentBoard[x][y] != empty)
			{
				killGroup(x, y, goBoard);
			}
		}
	}
}

void Rules::killGroup(uint8_t x, uint8_t y, GoBoard &goBoard)
{
	goBoard.PlayStone(x, y, empty);
	currentBoard = goBoard.ReturnGoBoardBoard();
	if (x < currentBoard.size() - 1)
		if (currentBoard[y][x + 1] == currentStone)
			killGroup(x + 1, y, goBoard);
	if (y < currentBoard.size() - 1)
		if (currentBoard[y + 1][x] == currentStone)
			killGroup(x, y + 1, goBoard);
	if (x)
		if (currentBoard[y][x - 1] == currentStone)
			killGroup(x - 1, y, goBoard);
	if (y)
		if (currentBoard[y - 1][x] == currentStone)
			killGroup(x, y - 1, goBoard);
}

uint8_t Rules::checkLibertiesOfAGroup(uint8_t x, uint8_t y)
{
	coordinate currentCoord;
	currentCoord.x = x;
	currentCoord.y = y;
	for (uint8_t i = 0; i < checkedCoordinates.size(); i++)
	{
		if (currentCoord.x == checkedCoordinates[i].x && currentCoord.y == checkedCoordinates[i].y)
		return liberties;
	}
	checkedCoordinates.push_back(currentCoord);

	checkliberties(x, y);
	if (x < currentBoard.size() - 1)
		if (currentBoard[x + 1][y] == currentStone)
			checkLibertiesOfAGroup(x + 1, y);
	if (y < currentBoard.size() - 1)
		if (currentBoard[x][y + 1] == currentStone)
			checkLibertiesOfAGroup(x, y + 1);
	if (x)
		if (currentBoard[x - 1][y] == currentStone)
			checkLibertiesOfAGroup(x - 1, y);
	if (y)
		if (currentBoard[x][y - 1] == currentStone)
			checkLibertiesOfAGroup(x, y - 1);
	return liberties;
}


void Rules::checkliberties(uint8_t x, uint8_t y)
{
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
}