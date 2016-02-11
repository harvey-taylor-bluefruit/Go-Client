#pragma once

#include "stdGoBoard.h"

class GoBoard
{
public:
	GoBoard(uint8_t goBoardSize);
	uint8_t ReturnGoBoardSize();
	board ReturnGoBoardBoard();

private:
	board CreateGoBoard();
	const uint8_t goBoardSize;
	board goBoardBoard;
};
