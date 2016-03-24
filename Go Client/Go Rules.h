#pragma once
#include "stdGoBoard.h"
#include "Go Board.h"
class Rules
{
public:
	Rules(GoBoard& goBoard);
	void KillTheDead(GoBoard &goBoard);
private:
	void KillGroup(uint8_t x, uint8_t y, GoBoard &goBoard);
	uint8_t CheckLibertiesOfAGroup(uint8_t x, uint8_t y);
	void CheckLiberties(uint8_t x, uint8_t y);

	struct coordinate
	{
		uint8_t x;
		uint8_t y;
	};
	board previousBoard;
	board currentBoard;
	std::vector<coordinate> checkedCoordinates;
	stone currentStone;
	uint8_t liberties;
};