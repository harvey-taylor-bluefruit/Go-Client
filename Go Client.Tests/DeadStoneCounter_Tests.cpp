#include "gtest/gtest.h"
#include "Go Rules.h"

TEST(StoneCounter, when_a_white_stone_dies_it_gets_counted)
{
	GoBoard testBoard(3);
	Rules testrules(testBoard);
	testBoard.PlayStone(1, 1, stone::white);
	testBoard.PlayStone(0, 1, stone::black);
	testBoard.PlayStone(1, 0, stone::black);
	testBoard.PlayStone(2, 1, stone::black);
	testBoard.PlayStone(1, 2, stone::black);
	testrules.DoRules(testBoard.ReturnWhosMoveIsNext(), testBoard);
	testrules.DoRules(testBoard.ReturnWhosMoveJustWent(), testBoard);
	EXPECT_EQ(1, testBoard.ReturnDeadStones(stone::white));
}

TEST(StoneCounter, when_a_black_stone_dies_it_gets_counted)
{
	GoBoard testBoard(3);
	Rules testrules(testBoard);
	testBoard.PlayStone(1, 1, stone::black);
	testBoard.PlayStone(0, 1, stone::white);
	testBoard.PlayStone(1, 0, stone::white);
	testBoard.PlayStone(2, 1, stone::white);
	testBoard.PlayStone(1, 2, stone::white);
	testrules.DoRules(testBoard.ReturnWhosMoveIsNext(), testBoard);
	testrules.DoRules(testBoard.ReturnWhosMoveJustWent(), testBoard);
	EXPECT_EQ(1, testBoard.ReturnDeadStones(stone::black));
}

TEST(StoneCounter, when_a_group_of_black_stones_die_they_get_counted)
{
	GoBoard testBoard(4);
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
	testrules.DoRules(testBoard.ReturnWhosMoveIsNext(), testBoard);
	testrules.DoRules(testBoard.ReturnWhosMoveJustWent(), testBoard);
	EXPECT_EQ(4, testBoard.ReturnDeadStones(stone::white));
}