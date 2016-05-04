 #include "Console.h"
#include <iostream>

using namespace Console;

void main()
{
   GameState Game(19);
	Rules rules(Game);
	while (1)
	{
		PrintBoard(Game);
		ObtainValidPlayerMove(Game);
		rules.DoRules(Game.WhosMoveIsNext(), Game);
		rules.DoRules(Game.WhosMoveJustWent(), Game);
	}
}