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
		{ stone::empty, stone::empty, stone::empty },
		{ stone::empty, stone::empty, stone::empty },
		{ stone::empty, stone::empty, stone::empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}

TEST(ConstructorTests, GoBoard_4by4)
{
	GoBoard Test(4);
	board testBoard = {
		{ stone::empty, stone::empty, stone::empty, stone::empty },
		{ stone::empty, stone::empty, stone::empty, stone::empty },
		{ stone::empty, stone::empty, stone::empty, stone::empty },
		{ stone::empty, stone::empty, stone::empty, stone::empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}

TEST(PlacingStoneTests, Play_white_On_1_1)
{
	GoBoard Test(3);
	board testBoard = {
		{ stone::empty, stone::empty, stone::empty },
		{ stone::empty, stone::empty, stone::empty },
		{ stone::empty, stone::empty, stone::empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
	Test.PlayStone(1, 1, stone::white);
	testBoard[1][1] = stone::white;
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}

TEST(PlacingStoneTests, play_black_on_1_1)
{
	GoBoard Test(3);
	board testBoard = {
		{ stone::empty, stone::empty, stone::empty },
		{ stone::empty, stone::empty, stone::empty },
		{ stone::empty, stone::empty, stone::empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
	Test.PlayStone(1, 1, stone::black);
	testBoard[1][1] = stone::black;
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}

TEST(PlacingStoneTests, play_black_on_0_0_and_white_on_1_1)
{
	GoBoard Test(3);
	board testBoard = {
		{ stone::empty, stone::empty, stone::empty },
		{ stone::empty, stone::empty, stone::empty },
		{ stone::empty, stone::empty, stone::empty } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
	Test.PlayStone(0, 0, stone::black);
	testBoard[0][0] = stone::black;
	Test.PlayStone(1, 1, stone::white);
	testBoard[1][1] = stone::white;
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}