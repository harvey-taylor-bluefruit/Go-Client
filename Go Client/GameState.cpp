#include "GameState.h"

using namespace std;

GameState::GameState(uint8_t goBoardSize) :
m_goBoardSize(goBoardSize), m_goBoard(CreateGoBoard()),
m_turn(stone::black), m_notTurn(stone::white),
m_prizonerBlackStones(0), m_prizonerWhiteStones(0)
{
}

uint8_t GameState::GoBoardSize()
{
   return m_goBoardSize;
}

board GameState::CreateGoBoard()
{
   board tempGoBoardBoard;
   for (uint8_t x = 0; x < m_goBoardSize; x++)
   {
      tempGoBoardBoard.push_back(vector<stone> {});
      for (uint8_t y = 0; y < m_goBoardSize; y++)
      {
         tempGoBoardBoard[x].push_back(stone::empty);
      }
   }
   return tempGoBoardBoard;
}

board GameState::GoBoard()
{
   return m_goBoard;
}

bool GameState::PlayStone(uint8_t X, uint8_t Y, stone stoneColour)
{
   if (m_goBoard[Y][X] != stone::empty && stoneColour != stone::empty)
      return false;

   m_goBoard[Y][X] = stoneColour;
   if (stoneColour == stone::white)
   {
      m_turn = stone::black;
      m_notTurn = stone::white;
   }
   if (stoneColour == stone::black)
   {
      m_turn = stone::white;
      m_notTurn = stone::black;
   }
   return true;
}

stone GameState::WhosMoveIsNext()
{
   return m_turn;
}

stone GameState::WhosMoveJustWent()
{
   return m_notTurn;
}

uint16_t GameState::PrizonerStones(stone stone)
{
   switch (stone)
   {
   case stone::white:
      return m_prizonerWhiteStones;
   case stone::black:
      return m_prizonerBlackStones;
   }
   return 0;
}

void GameState::IncrementDeadStones(stone stoneColour)
{
   switch (stoneColour)
   {
   case stone::white:
      m_prizonerWhiteStones++;
      break;
   case stone::black:
      m_prizonerBlackStones++;
      break;
   }
}