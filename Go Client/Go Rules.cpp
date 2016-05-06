#include "Go Rules.h"

Rules::Rules(GameState &goBoard) :
	currentBoard(goBoard.GoBoard())
{
}

void Rules::DoRules(stone stoneChecking, GameState &goBoard)
{
	currentBoard = goBoard.GoBoard();
	for (uint8_t x = 0; x < currentBoard.size(); ++x)
	{
		for (uint8_t y = 0; y < currentBoard.size(); ++y)
		{
			CheckRules(x, y, goBoard, stoneChecking);
		}
	}
}

void Rules::CheckRules(uint8_t x, uint8_t y, GameState &goBoard, stone StoneChecking)
{
	currentBoard = goBoard.GoBoard();
	checkedCoordinates = {};
	currentStone = currentBoard[y][x];
	liberties = 0;
	if (currentStone == StoneChecking)
	{
		if (NumberOflibertiesOfAGroup(x, y) == 0)
		{
			KillGroup(x, y, goBoard);
		}
	}
}

void Rules::KillGroup(uint8_t x, uint8_t y, GameState &goBoard)
{
	goBoard.IncrementDeadStones(currentStone);
	goBoard.PlayStone(x, y, stone::empty);
	currentBoard = goBoard.GoBoard();
	if (x < currentBoard.size() - 1)
		if (currentBoard[y][x + 1] == currentStone)
			KillGroup( x + 1, y, goBoard);
	if (y < currentBoard.size() - 1)
		if (currentBoard[y + 1][x] == currentStone)
			KillGroup( x, y + 1, goBoard);
	if (x)
		if (currentBoard[y][x - 1] == currentStone)
			KillGroup( x - 1, y, goBoard);
	if (y)
		if (currentBoard[y - 1][x] == currentStone)
			KillGroup( x, y - 1,  goBoard);
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
		if (currentBoard[y][x + 1] == currentStone)
			NumberOflibertiesOfAGroup(x + 1, y);
	if (y < currentBoard.size() - 1)
		if (currentBoard[y + 1][x] == currentStone)
			NumberOflibertiesOfAGroup(x, y + 1);
	if (x)
		if (currentBoard[y][x - 1] == currentStone)
			NumberOflibertiesOfAGroup(x - 1, y);
	if (y)
		if (currentBoard[y - 1][x] == currentStone)
			NumberOflibertiesOfAGroup(x, y - 1);
	return liberties;
}

void Rules::CheckLibertiesOfAStone(uint8_t x, uint8_t y)
{
	if (x < currentBoard.size()-1 && (currentBoard[y][x + 1] == stone::empty))
		++liberties;
	if (y < currentBoard.size()-1 && (currentBoard[y + 1][x] == stone::empty))
		++liberties;
	if (x && (currentBoard[y][x - 1] == stone::empty))
		++liberties;
	if (y && (currentBoard[y - 1][x] == stone::empty))
		++liberties;
}
