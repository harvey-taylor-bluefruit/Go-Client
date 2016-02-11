#include "Go Client.h"

GoBoard::GoBoard(uint8_t GoBoardSize):
	GoBoardSize(GoBoardSize)
{
}

uint8_t GoBoard::ReturnGoBoardSize()
{
	return GoBoardSize;
}