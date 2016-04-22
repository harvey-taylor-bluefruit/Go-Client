#pragma once

#include "..\Go Client\Go Rules.h"
#include <string>

namespace ConsoleFuntions
{
	void PrintBoard(GoBoard &goBoard);
	void OutputDeadStones(GoBoard &goBoard);
	void ObtainValidPlayerMove(GoBoard &goBoard);
	bool GetCoordinatesAndPlay(GoBoard &goBoard);
	uint8_t GetInput(std::string message);
};