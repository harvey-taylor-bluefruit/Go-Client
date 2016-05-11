#pragma once

#include "stdGoBoard.h"

class GameState
{
public:
   GameState(uint8_t goBoardSize);
	uint8_t GoBoardSize();
	bool PlayStone(uint8_t X, uint8_t Y, stone);
	board GoBoard();
	stone WhosMoveIsNext();
	stone WhosMoveJustWent();
	uint16_t PrizonerStones(stone stone);
	void IncrementDeadStones(stone stone);
private:
	uint16_t m_deadWhiteStones;
	uint16_t m_deadBlackStones;
	board CreateGoBoard();
	const uint8_t m_goBoardSize;
	board m_goBoard;
	stone m_turn;
	stone m_notTurn;
};
