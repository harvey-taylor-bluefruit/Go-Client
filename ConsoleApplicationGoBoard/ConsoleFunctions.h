#pragma once

#include "..\Go Client\Go Rules.h"
#include <string>

namespace ConsoleFuntions
{
	void PrintBoard(GoBoard &goBoard);
	void playerMove(GoBoard &goBoard);
	bool GetCoordiatesAndPlay(GoBoard &goBoard);
	uint8_t GetInput(std::string message);
};