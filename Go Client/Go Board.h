#pragma once

#include "stdGoBoard.h"

class GoBoard
{
public:
	GoBoard(uint8_t goBoardSize);
	uint8_t ReturnGoBoardSize();
	bool PlayStone(uint8_t X, uint8_t Y, stone);
	board ReturnGoBoard();
	stone ReturnWhosMoveIsNext();
	stone ReturnWhosMoveJustWent();
private:
	board CreateGoBoard();
	const uint8_t goBoardSize;
	board goBoard;
	stone turn;
	stone notTurn;
};
