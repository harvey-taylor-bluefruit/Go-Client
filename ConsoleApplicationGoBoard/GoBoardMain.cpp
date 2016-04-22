#include "ConsoleFunctions.h"
#include <iostream>

using namespace ConsoleFunctions;

void main()
{
	GoBoard Game(19);
	Rules rules(Game);
	while (1)
	{
		PrintBoard(Game);
		ObtainValidPlayerMove(Game);
		rules.DoRules(Game.ReturnWhosMoveIsNext(), Game);
		rules.DoRules(Game.ReturnWhosMoveJustWent(), Game);
	}
}