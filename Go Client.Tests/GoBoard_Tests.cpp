#include "gtest/gtest.h"
#include "Go Board.h"

TEST(ConstructorTests, GoBoard_size1)
{
	GoBoard Test(1);
	EXPECT_EQ(1, Test.ReturnGoBoardSize());
}

TEST(ConstructorTests, GoBoard_size2)
{
	GoBoard Test(13);
	EXPECT_EQ(13, Test.ReturnGoBoardSize());
}

TEST(ConstructorTests, GoBoard_3by3)
{
	GoBoard Test(3);
	board testBoard = {
		{ empty, empty, empty },
		{ empty, empty, empty },
		{ empty, empty, empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}

TEST(ConstructorTests, GoBoard_4by4)
{
	GoBoard Test(4);
	board testBoard = {
		{ empty, empty, empty, empty },
		{ empty, empty, empty, empty },
		{ empty, empty, empty, empty },
		{ empty, empty, empty, empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}

TEST(PlacingStoneTests, Play_white_On_1_1)
{
	GoBoard Test(3);
	board testBoard = {
		{ empty, empty, empty },
		{ empty, empty, empty },
		{ empty, empty, empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
	Test.PlayStone(1, 1, white);
	testBoard[1][1] = white;
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}

TEST(PlacingStoneTests, play_black_on_1_1)
{
	GoBoard Test(3);
	board testBoard = {
		{ empty, empty, empty },
		{ empty, empty, empty },
		{ empty, empty, empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
	Test.PlayStone(1, 1, black);
	testBoard[1][1] = black;
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}

TEST(PlacingStoneTests, play_black_on_0_0_and_white_on_1_1)
{
	GoBoard Test(3);
	board testBoard = {
		{ empty, empty, empty },
		{ empty, empty, empty },
		{ empty, empty, empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
	Test.PlayStone(0, 0, black);
	testBoard[0][0] = black;
	Test.PlayStone(1, 1, white);
	testBoard[1][1] = white;
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}