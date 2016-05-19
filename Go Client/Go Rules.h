#pragma once

#include "GameState.h"

class Rules
{
public:
   Rules(GameState& gameState);
   void DoRules(stone stoneChecking, GameState &gameState);
private:
   void CheckRules(uint8_t x, uint8_t y, GameState &gameState, stone StoneChecking);
   void KillGroup(uint8_t x, uint8_t y, GameState &gameState);
   uint8_t NumberOflibertiesOfAGroup(uint8_t x, uint8_t y);
   void CheckLibertiesOfAStone(uint8_t x, uint8_t y);

   struct coordinate
   {
      uint8_t x;
      uint8_t y;
   };

   board m_previousBoard;
   board m_currentBoard;
   std::vector<coordinate> m_checkedCoordinates;
   stone m_currentStone;
   uint8_t m_liberties;
};