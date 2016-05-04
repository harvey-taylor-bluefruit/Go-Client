#pragma once
#include "stdGoBoard.h"
#include "Go Board.h"
class Rules
{
public:
   Rules(GameState& goBoard);
   void DoRules(stone stoneChecking, GameState &goBoard);
private:
   void CheckRules(uint8_t x, uint8_t y, GameState &goBoard, stone StoneChecking);
   void KillGroup(uint8_t x, uint8_t y, GameState &goBoard);
	uint8_t NumberOflibertiesOfAGroup(uint8_t x, uint8_t y);
	void CheckLibertiesOfAStone(uint8_t x, uint8_t y);

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