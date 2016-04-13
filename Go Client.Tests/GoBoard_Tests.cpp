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
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY },
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY },
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}

TEST(ConstructorTests, GoBoard_4by4)
{
	GoBoard Test(4);
	board testBoard = {
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY, stone::EMPTY },
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY, stone::EMPTY },
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY, stone::EMPTY },
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY, stone::EMPTY } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}

TEST(PlacingStoneTests, Play_WHITE_On_1_1)
{
	GoBoard Test(3);
	board testBoard = {
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY },
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY },
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
	Test.PlayStone(1, 1, stone::WHITE);
	testBoard[1][1] = stone::WHITE;
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}

TEST(PlacingStoneTests, play_BLACK_on_1_1)
{
	GoBoard Test(3);
	board testBoard = {
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY },
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY },
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
	Test.PlayStone(1, 1, stone::BLACK);
	testBoard[1][1] = stone::BLACK;
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}

TEST(PlacingStoneTests, play_BLACK_on_0_0_and_WHITE_on_1_1)
{
	GoBoard Test(3);
	board testBoard = {
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY },
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY },
		{ stone::EMPTY, stone::EMPTY, stone::EMPTY } };
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
	Test.PlayStone(0, 0, stone::BLACK);
	testBoard[0][0] = stone::BLACK;
	Test.PlayStone(1, 1, stone::WHITE);
	testBoard[1][1] = stone::WHITE;
	EXPECT_EQ(testBoard, Test.ReturnGoBoard());
}