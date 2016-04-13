#include "Go Rules.h"

Rules::Rules(GoBoard &goBoard):
	currentBoard(goBoard.ReturnGoBoard())
{
}

void Rules::DoRules(stone StoneChecking, GoBoard &goBoard)
{
	currentBoard = goBoard.ReturnGoBoard();
	for (uint8_t x = 0; x < currentBoard.size(); ++x)
	{
		for (uint8_t y = 0; y < currentBoard.size(); ++y)
		{
			currentBoard = goBoard.ReturnGoBoard();
			checkedCoordinates = {};
			currentStone = currentBoard[x][y];
			liberties = 0;
			if (currentBoard[x][y] == StoneChecking)
			{
				if (NumberOflibertiesOfAGroup(x, y) == 0)
				{
					KillGroup(x, y, goBoard);
				}
			}
		}
	}
}

void Rules::KillGroup(uint8_t x, uint8_t y, GoBoard &goBoard)
{
	goBoard.PlayStone(y, x, stone::EMPTY);
	currentBoard = goBoard.ReturnGoBoard();
	if (x < currentBoard.size() - 1)
		if (currentBoard[y][x + 1] == currentStone)
			KillGroup(y, x + 1, goBoard);
	if (y < currentBoard.size() - 1)
		if (currentBoard[y + 1][x] == currentStone)
			KillGroup(y + 1, x, goBoard);
	if (x)
		if (currentBoard[y][x - 1] == currentStone)
			KillGroup(y, x - 1,  goBoard);
	if (y)
		if (currentBoard[y - 1][x] == currentStone)
			KillGroup(y - 1, x,  goBoard);
}

uint8_t Rules::NumberOflibertiesOfAGroup(uint8_t x, uint8_t y)
{
	coordinate currentCoord;
	currentCoord.x = x;
	currentCoord.y = y;

	for (uint16_t i = 0; i < checkedCoordinates.size(); i++)
	{
		if (currentCoord.x == checkedCoordinates[i].x && currentCoord.y == checkedCoordinates[i].y)
		return liberties;
	}
	checkedCoordinates.push_back(currentCoord);

	CheckLibertiesOfAStone(x, y);
	if (x < currentBoard.size() - 1)
		if (currentBoard[x + 1][y] == currentStone)
			NumberOflibertiesOfAGroup(x + 1, y);
	if (y < currentBoard.size() - 1)
		if (currentBoard[x][y + 1] == currentStone)
			NumberOflibertiesOfAGroup(x, y + 1);
	if (x)
		if (currentBoard[x - 1][y] == currentStone)
			NumberOflibertiesOfAGroup(x - 1, y);
	if (y)
		if (currentBoard[x][y - 1] == currentStone)
			NumberOflibertiesOfAGroup(x, y - 1);
	
	return liberties;
}

void Rules::CheckLibertiesOfAStone(uint8_t x, uint8_t y)
{
	if (x < currentBoard.size()-1)
		if (currentBoard[x + 1][y] == stone::EMPTY)
			++liberties;
	if (y < currentBoard.size()-1)
		if (currentBoard[x][y + 1] == stone::EMPTY)
			++liberties;
	if (x)
		if (currentBoard[x - 1][y] == stone::EMPTY)
			++liberties;
	if (y)
		if (currentBoard[x][y - 1] == stone::EMPTY)
			++liberties;
}
