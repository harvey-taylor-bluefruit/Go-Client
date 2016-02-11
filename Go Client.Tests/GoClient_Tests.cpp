#include "gtest/gtest.h"
#include "Go Client.h"

TEST(ConstructorTests, GoBoardsize1)
{
	GoBoard Test(1);
	EXPECT_EQ(1, Test.ReturnGoBoardSize());
}

TEST(ConstructorTests, GoBoardsize2)
{
	GoBoard Test(13);
	EXPECT_EQ(13, Test.ReturnGoBoardSize());
}

TEST(ConstructorTests, GoBoardBoard3by3)
{
	GoBoard Test(3);
	board testBoard = {
		{ empty, empty, empty },
		{ empty, empty, empty },
		{ empty, empty, empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoardBoard());
}

TEST(ConstructorTests, GoBoardBoard4by4)
{
	GoBoard Test(4);
	board testBoard = {
		{ empty, empty, empty, empty },
		{ empty, empty, empty, empty },
		{ empty, empty, empty, empty },
		{ empty, empty, empty, empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoardBoard());
}

TEST(PlacingStoneTests, playwhiteOn1_1)
{
	GoBoard Test(3);
	board testBoard = {
		{ empty, empty, empty },
		{ empty, empty, empty },
		{ empty, empty, empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoardBoard());
	Test.PlayStone(1, 1, white);
	testBoard[1][1] = white;
	EXPECT_EQ(testBoard, Test.ReturnGoBoardBoard());
}

TEST(PlacingStoneTests, playblackOn1_1)
{
	GoBoard Test(3);
	board testBoard = {
		{ empty, empty, empty },
		{ empty, empty, empty },
		{ empty, empty, empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoardBoard());
	Test.PlayStone(1, 1, black);
	testBoard[1][1] = black;
	EXPECT_EQ(testBoard, Test.ReturnGoBoardBoard());
}

TEST(PlacingStoneTests, playblackOn_0_0_andWhiteOn_1_1)
{
	GoBoard Test(3);
	board testBoard = {
		{ empty, empty, empty },
		{ empty, empty, empty },
		{ empty, empty, empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoardBoard());
	Test.PlayStone(0, 0, black);
	testBoard[0][0] = black;
	Test.PlayStone(1, 1, white);
	testBoard[1][1] = white;
	EXPECT_EQ(testBoard, Test.ReturnGoBoardBoard());
}