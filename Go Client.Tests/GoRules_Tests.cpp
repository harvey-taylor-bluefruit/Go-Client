#include "gtest/gtest.h"
#include "Go Rules.h"

TEST(Rules, Stone_dies_when_it_becomes_surrounded)
{
	GoBoard testBoard(3);
	board expectedboard =
	{	{ stone::EMPTY, stone::BLACK, stone::EMPTY},
		{ stone::BLACK, stone::EMPTY, stone::EMPTY},
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY}};
	Rules testrules(testBoard);
	testBoard.PlayStone(0, 1, stone::BLACK);
	testBoard.PlayStone(0, 0, stone::WHITE);
	testBoard.PlayStone(1, 0, stone::BLACK);
	testrules.DoRules(testBoard.ReturnTurn(), testBoard);
	testrules.DoRules(testBoard.ReturnNotTurn(), testBoard);
	EXPECT_EQ(expectedboard, testBoard.ReturnGoBoard());
}

TEST(Rules, Stone_dosent_die_when_sorounded_by_its_own_stones)
{
	GoBoard testBoard(3);
	board expectedboard =
	{ { stone::EMPTY, stone::BLACK, stone::EMPTY },
	{ stone::BLACK, stone::BLACK, stone::BLACK },
	{ stone::EMPTY, stone::BLACK, stone::EMPTY } };
	Rules testrules(testBoard);
	testBoard.PlayStone(0, 1, stone::BLACK);
	testBoard.PlayStone(1, 1, stone::BLACK);
	testBoard.PlayStone(1, 0, stone::BLACK);
	testBoard.PlayStone(1, 2, stone::BLACK);
	testBoard.PlayStone(2, 1, stone::BLACK);
	testrules.DoRules(testBoard.ReturnTurn(), testBoard);
	testrules.DoRules(testBoard.ReturnNotTurn(), testBoard);
	EXPECT_EQ(expectedboard, testBoard.ReturnGoBoard());
}

TEST(Rules, Group_death)
{
	GoBoard testBoard(3);
	board expectedboard =
	{ { stone::EMPTY, stone::BLACK, stone::BLACK },
	{ stone::BLACK, stone::EMPTY, stone::EMPTY },
	{ stone::EMPTY, stone::BLACK, stone::BLACK } };
	Rules testrules(testBoard);
	testBoard.PlayStone(0, 1, stone::BLACK);
	testBoard.PlayStone(1, 2, stone::BLACK);
	testBoard.PlayStone(1, 0, stone::BLACK);
	testBoard.PlayStone(2, 0, stone::BLACK);
	testBoard.PlayStone(2, 2, stone::BLACK);
	testBoard.PlayStone(1, 1, stone::WHITE);
	testBoard.PlayStone(2, 1, stone::WHITE);
	testrules.DoRules(testBoard.ReturnTurn(), testBoard);
	testrules.DoRules(testBoard.ReturnNotTurn(), testBoard);
	EXPECT_EQ(expectedboard, testBoard.ReturnGoBoard());
}

TEST(Rules, Correct_Group_Dies_depending_on_Whos_turn_it_it)
{
	GoBoard testBoard(4);
	board expectedboard =
	{ { stone::EMPTY, stone::BLACK, stone::WHITE, stone::EMPTY},
	{ stone::BLACK, stone::WHITE, stone::EMPTY, stone::WHITE },
	{ stone::EMPTY, stone::BLACK, stone::WHITE, stone::EMPTY },
	{ stone::EMPTY, stone::EMPTY, stone::EMPTY, stone::EMPTY } };
	Rules testrules(testBoard);
	testBoard.PlayStone(1, 0, stone::BLACK);
	testBoard.PlayStone(2, 0, stone::WHITE);
	testBoard.PlayStone(0, 1, stone::BLACK);
	testBoard.PlayStone(3, 1, stone::WHITE);
	testBoard.PlayStone(2, 1, stone::BLACK);
	testBoard.PlayStone(2, 2, stone::WHITE);
	testBoard.PlayStone(1, 2, stone::BLACK);
	testBoard.PlayStone(1, 1, stone::WHITE);
	testrules.DoRules(testBoard.ReturnTurn(), testBoard);
	testrules.DoRules(testBoard.ReturnNotTurn(), testBoard);
	EXPECT_EQ(expectedboard, testBoard.ReturnGoBoard());
}