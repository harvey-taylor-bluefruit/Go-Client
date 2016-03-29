#pragma once

#include "stdGoBoard.h"

class GoBoard
{
public:
	GoBoard(uint8_t goBoardSize);
	uint8_t ReturnGoBoardSize();
	void PlayStone(uint8_t X, uint8_t Y, stone);
	board ReturnGoBoard();
	stone ReturnTurn();
private:
	board CreateGoBoard();
	const uint8_t goBoardSize;
	board goBoardBoard;
	stone turn;
};
