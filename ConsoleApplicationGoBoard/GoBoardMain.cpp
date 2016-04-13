#include "ConsoleFunctions.h"
#include <iostream>

using namespace ConsoleFuntions;

void main()
{
	GoBoard Game(19);
	Rules rules(Game);
	while (1)
	{
		PrintBoard(Game);
		playerMove(Game);
		rules.DoRules(Game.ReturnTurn(), Game);
		rules.DoRules(Game.ReturnNotTurn(), Game);
	}
}