#pragma once

#include "..\Go Client\Go Rules.h"
#include <string>

namespace Console
{
   const void PrintBoard(GameState &goBoard);
   const void OutputDeadStones(GameState &goBoard);
   void ObtainValidPlayerMove(GameState &goBoard);
   bool GetCoordinatesAndPlay(GameState &goBoard);
   uint8_t GetInput(const std::string &message);
};