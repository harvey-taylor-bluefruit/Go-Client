#include "gtest/gtest.h"
#include "Go Rules.h"

TEST(Rules, Stone_dies)
{
	GoBoard testBoard(3);
	board expectedboard =
	{	{empty, black, empty},
		{black, empty, empty},
		{empty, empty, empty}};
	Rules testrules(testBoard);
	testBoard.PlayStone(0, 1, black);
	testBoard.PlayStone(0, 0, white);
	testBoard.PlayStone(1, 0, black);
	testrules.KillTheDead(testBoard);
	EXPECT_EQ(expectedboard, testBoard.ReturnGoBoard());
}

TEST(Rules, Stone_dosent_die_when_sorounded_by_its_own_stones)
{
	GoBoard testBoard(3);
	board expectedboard =
	{ { empty, black, empty },
	{ black, black, black },
	{ empty, black, empty } };
	Rules testrules(testBoard);
	testBoard.PlayStone(0, 1, black);
	testBoard.PlayStone(1, 1, black);
	testBoard.PlayStone(1, 0, black);
	testBoard.PlayStone(1, 2, black);
	testBoard.PlayStone(2, 1, black);
	testrules.KillTheDead(testBoard);
	EXPECT_EQ(expectedboard, testBoard.ReturnGoBoard());
}

TEST(Rules, Group_death)
{
	GoBoard testBoard(3);
	board expectedboard =
	{ { empty, black, black },
	{ black, empty, empty },
	{ empty, black, black } };
	Rules testrules(testBoard);
	testBoard.PlayStone(0, 1, black);
	testBoard.PlayStone(1, 2, black);
	testBoard.PlayStone(1, 0, black);
	testBoard.PlayStone(2, 0, black);
	testBoard.PlayStone(2, 2, black);
	testBoard.PlayStone(1, 1, white);
	testBoard.PlayStone(2, 1, white);
	testrules.KillTheDead(testBoard);
	EXPECT_EQ(expectedboard, testBoard.ReturnGoBoard());
}