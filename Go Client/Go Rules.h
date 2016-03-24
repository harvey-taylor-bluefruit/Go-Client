#pragma once
#include "stdGoBoard.h"
#include "Go Board.h"

class Rules
{
public:
	Rules(GoBoard& goBoard);
	void killthedead(GoBoard &goBoard);
private:
	uint8_t checkLibertiesOfAGroup(uint8_t x, uint8_t y);
	uint8_t checkliberties(uint8_t x, uint8_t y);
	board previousBoard;
	board currentBoard;
};