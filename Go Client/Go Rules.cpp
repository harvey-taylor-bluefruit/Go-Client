#include "Go Rules.h"

Rules::Rules(GameState &goBoard) :
	m_currentBoard(goBoard.GoBoard())
{
}

void Rules::DoRules(stone stoneChecking, GameState &goBoard)
{
   m_currentBoard = goBoard.GoBoard();
   for (uint8_t x = 0; x < m_currentBoard.size(); ++x)
	{
      for (uint8_t y = 0; y < m_currentBoard.size(); ++y)
		{
			CheckRules(x, y, goBoard, stoneChecking);
		}
	}
}

void Rules::CheckRules(uint8_t x, uint8_t y, GameState &goBoard, stone stoneChecking)
{
   m_currentBoard = goBoard.GoBoard();
   m_checkedCoordinates = {};
   m_currentStone = m_currentBoard[y][x];
   m_liberties = 0;
   if (m_currentStone == stoneChecking)
	{
		if (NumberOflibertiesOfAGroup(x, y) == 0)
		{
			KillGroup(x, y, goBoard);
		}
	}
}

void Rules::KillGroup(uint8_t x, uint8_t y, GameState &goBoard)
{
   goBoard.IncrementDeadStones(m_currentStone);
	goBoard.PlayStone(x, y, stone::empty);
   m_currentBoard = goBoard.GoBoard();
   if (x < m_currentBoard.size() - 1)
      if (m_currentBoard[y][x + 1] == m_currentStone)
			KillGroup( x + 1, y, goBoard);
   if (y < m_currentBoard.size() - 1)
      if (m_currentBoard[y + 1][x] == m_currentStone)
			KillGroup( x, y + 1, goBoard);
	if (x)
      if (m_currentBoard[y][x - 1] == m_currentStone)
			KillGroup( x - 1, y, goBoard);
	if (y)
      if (m_currentBoard[y - 1][x] == m_currentStone)
			KillGroup( x, y - 1,  goBoard);
}

uint8_t Rules::NumberOflibertiesOfAGroup(uint8_t x, uint8_t y)
{
	coordinate currentCoord;
	currentCoord.x = x;
	currentCoord.y = y;

   for (uint16_t i = 0; i < m_checkedCoordinates.size(); i++)
	{
      if (currentCoord.x == m_checkedCoordinates[i].x && currentCoord.y == m_checkedCoordinates[i].y)
         return m_liberties;
	}
   m_checkedCoordinates.push_back(currentCoord);

	CheckLibertiesOfAStone(x, y);
   if (x < m_currentBoard.size() - 1)
      if (m_currentBoard[y][x + 1] == m_currentStone)
			NumberOflibertiesOfAGroup(x + 1, y);
   if (y < m_currentBoard.size() - 1)
      if (m_currentBoard[y + 1][x] == m_currentStone)
			NumberOflibertiesOfAGroup(x, y + 1);
	if (x)
      if (m_currentBoard[y][x - 1] == m_currentStone)
			NumberOflibertiesOfAGroup(x - 1, y);
	if (y)
      if (m_currentBoard[y - 1][x] == m_currentStone)
			NumberOflibertiesOfAGroup(x, y - 1);
   return m_liberties;
}

void Rules::CheckLibertiesOfAStone(uint8_t x, uint8_t y)
{
   if (x < m_currentBoard.size() - 1 && (m_currentBoard[y][x + 1] == stone::empty))
      ++m_liberties;
   if (y < m_currentBoard.size() - 1 && (m_currentBoard[y + 1][x] == stone::empty))
      ++m_liberties;
   if (x && (m_currentBoard[y][x - 1] == stone::empty))
      ++m_liberties;
   if (y && (m_currentBoard[y - 1][x] == stone::empty))
      ++m_liberties;
}
