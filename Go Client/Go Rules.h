#pragma once
#include "stdGoBoard.h"
#include "Go Board.h"

class Rules
{
public:
	Rules(GoBoard& goBoard);
	void killthedead(GoBoard &goBoard);
private:
	void killGroup(uint8_t x, uint8_t y, GoBoard &goBoard);
	uint8_t checkLibertiesOfAGroup(uint8_t x, uint8_t y);
	void checkliberties(uint8_t x, uint8_t y);
	board previousBoard;
	board currentBoard;
	std::vector<coordinate> checkedCoordinates;
	stone currentStone;
	uint8_t liberties;
};