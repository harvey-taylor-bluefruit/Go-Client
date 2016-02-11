#include "Go Client.h"

using namespace std;

GoBoard::GoBoard(uint8_t goBoardSize) :
goBoardSize(goBoardSize), goBoardBoard(CreateGoBoard())
{

}

uint8_t GoBoard::ReturnGoBoardSize()
{
	return goBoardSize;
}

board GoBoard::CreateGoBoard()
{
	board tempGoBoardBoard;
	for (uint8_t x = 0; x < goBoardSize; x++)
	{
		tempGoBoardBoard.push_back(vector<stone> {});
		for (uint8_t y = 0; y < goBoardSize; y++)
		{
			tempGoBoardBoard[x].push_back(empty);
		}
	}
	return tempGoBoardBoard;
}

board GoBoard::ReturnGoBoardBoard()
{
	return goBoardBoard;
}