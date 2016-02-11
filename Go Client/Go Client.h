#pragma once
#include <stdint.h>

class GoBoard
{
public:
	GoBoard(uint8_t GoBoardSize);
	uint8_t ReturnGoBoardSize();
private:
	const uint8_t GoBoardSize;
};
