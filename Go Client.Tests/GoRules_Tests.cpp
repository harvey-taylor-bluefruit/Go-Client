#include "gtest/gtest.h"
#include "Go Rules.h"

TEST(Rules, StoneDies)
{
	GoBoard testboard(3);
	board expectedboard =
	{	{empty, black, empty},
		{black, empty, empty},
		{empty, empty, empty}};
	Rules testrules(testboard);
	testboard.PlayStone(0, 1, black);
	testboard.PlayStone(0, 0, white);
	testboard.PlayStone(1, 0, black);
	testrules.killthedead(testboard);
	EXPECT_EQ(expectedboard, testboard.ReturnGoBoardBoard());
}

TEST(Rules, StoneDosentDieWhenSoroundedByItsOwnStones)
{
	GoBoard testboard(3);
	board expectedboard =
	{ { empty, black, empty },
	{ black, black, black },
	{ empty, black, empty } };
	Rules testrules(testboard);
	testboard.PlayStone(0, 1, black);
	testboard.PlayStone(1, 1, black);
	testboard.PlayStone(1, 0, black);
	testboard.PlayStone(1, 2, black);
	testboard.PlayStone(2, 1, black);
	testrules.killthedead(testboard);
	EXPECT_EQ(expectedboard, testboard.ReturnGoBoardBoard());
}

TEST(Rules, groupdeath)
{
	GoBoard testboard(3);
	board expectedboard =
	{ { empty, black, black },
	{ black, empty, empty },
	{ empty, black, black } };
	Rules testrules(testboard);
	testboard.PlayStone(0, 1, black);
	testboard.PlayStone(1, 2, black);
	testboard.PlayStone(1, 0, black);
	testboard.PlayStone(2, 0, black);
	testboard.PlayStone(2, 2, black);
	testboard.PlayStone(1, 1, white);
	testboard.PlayStone(2, 1, white);
	testrules.killthedead(testboard);
	EXPECT_EQ(expectedboard, testboard.ReturnGoBoardBoard());
}