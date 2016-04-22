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
	uint16_t ReturnDeadStones(stone stone);
	void IncrimentDeadStones(stone stone);
private:
	uint16_t deadWhiteStones;
	uint16_t deadBlackStones;
	board CreateGoBoard();
	const uint8_t goBoardSize;
	board goBoard;
	stone turn;
	stone notTurn;
};
