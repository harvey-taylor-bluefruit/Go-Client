#include "gtest/gtest.h"
#include "Go Rules.h"

TEST(Rules, Stone_dies_when_it_becomes_surrounded)
{
   GameState testBoard(3);
   board expectedboard =
   { { stone::empty, stone::black, stone::empty },
   { stone::black, stone::empty, stone::empty },
   { stone::empty, stone::empty, stone::empty } };
   Rules testrules(testBoard);
   testBoard.PlayStone(0, 1, stone::black);
   testBoard.PlayStone(0, 0, stone::white);
   testBoard.PlayStone(1, 0, stone::black);
   testrules.DoRules(testBoard.WhosMoveIsNext(), testBoard);
   testrules.DoRules(testBoard.WhosMoveJustWent(), testBoard);
   EXPECT_EQ(expectedboard, testBoard.GoBoard());
}

TEST(Rules, Stone_dosent_die_when_sorounded_by_its_own_stones)
{
   GameState testBoard(3);
   board expectedboard =
   { { stone::empty, stone::black, stone::empty },
   { stone::black, stone::black, stone::black },
   { stone::empty, stone::black, stone::empty } };
   Rules testrules(testBoard);
   testBoard.PlayStone(0, 1, stone::black);
   testBoard.PlayStone(1, 1, stone::black);
   testBoard.PlayStone(1, 0, stone::black);
   testBoard.PlayStone(1, 2, stone::black);
   testBoard.PlayStone(2, 1, stone::black);
   testrules.DoRules(testBoard.WhosMoveIsNext(), testBoard);
   testrules.DoRules(testBoard.WhosMoveJustWent(), testBoard);
   EXPECT_EQ(expectedboard, testBoard.GoBoard());
}

TEST(Rules, Group_death)
{
   GameState testBoard(3);
   board expectedboard =
   { { stone::empty, stone::black, stone::black },
   { stone::black, stone::empty, stone::empty },
   { stone::empty, stone::black, stone::black } };
   Rules testrules(testBoard);
   testBoard.PlayStone(0, 1, stone::black);
   testBoard.PlayStone(1, 2, stone::black);
   testBoard.PlayStone(1, 0, stone::black);
   testBoard.PlayStone(2, 0, stone::black);
   testBoard.PlayStone(2, 2, stone::black);
   testBoard.PlayStone(1, 1, stone::white);
   testBoard.PlayStone(2, 1, stone::white);
   testrules.DoRules(testBoard.WhosMoveIsNext(), testBoard);
   testrules.DoRules(testBoard.WhosMoveJustWent(), testBoard);
   EXPECT_EQ(expectedboard, testBoard.GoBoard());
}

TEST(Rules, Correct_Group_Dies_depending_on_Whos_turn_it_it)
{
   GameState testBoard(4);
   board expectedboard =
   { { stone::empty, stone::black, stone::white, stone::empty },
   { stone::black, stone::white, stone::empty, stone::white },
   { stone::empty, stone::black, stone::white, stone::empty },
   { stone::empty, stone::empty, stone::empty, stone::empty } };
   Rules testrules(testBoard);
   testBoard.PlayStone(1, 0, stone::black);
   testBoard.PlayStone(2, 0, stone::white);
   testBoard.PlayStone(0, 1, stone::black);
   testBoard.PlayStone(3, 1, stone::white);
   testBoard.PlayStone(2, 1, stone::black);
   testBoard.PlayStone(2, 2, stone::white);
   testBoard.PlayStone(1, 2, stone::black);
   testBoard.PlayStone(1, 1, stone::white);
   testrules.DoRules(testBoard.WhosMoveIsNext(), testBoard);
   testrules.DoRules(testBoard.WhosMoveJustWent(), testBoard);
   EXPECT_EQ(expectedboard, testBoard.GoBoard());
}

TEST(Rules, Correct_Group_Dies_depending_on_Whos_turn_it_is_agianst_an_edge_L_shape)
{
   GameState testBoard(4);
   board expectedboard =
   { { stone::empty, stone::black, stone::empty, stone::empty },
   { stone::empty, stone::black, stone::empty, stone::empty },
   { stone::empty, stone::empty, stone::black, stone::empty },
   { stone::black, stone::black, stone::empty, stone::empty } };
   Rules testrules(testBoard);
   testBoard.PlayStone(1, 0, stone::black);
   testBoard.PlayStone(0, 0, stone::white);
   testBoard.PlayStone(0, 3, stone::black);
   testBoard.PlayStone(0, 1, stone::white);
   testBoard.PlayStone(2, 2, stone::black);
   testBoard.PlayStone(0, 2, stone::white);
   testBoard.PlayStone(1, 1, stone::black);
   testBoard.PlayStone(1, 2, stone::white);
   testBoard.PlayStone(1, 3, stone::black);
   testrules.DoRules(testBoard.WhosMoveIsNext(), testBoard);
   testrules.DoRules(testBoard.WhosMoveJustWent(), testBoard);
   EXPECT_EQ(expectedboard, testBoard.GoBoard());
}