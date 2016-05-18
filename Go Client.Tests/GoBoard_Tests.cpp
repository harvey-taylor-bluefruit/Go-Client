#include "gtest/gtest.h"
#include "GameState.h"

TEST(ConstructorTests, GoBoard_size1)
{
   GameState Test(1);
   EXPECT_EQ(1, Test.GoBoardSize());
}

TEST(ConstructorTests, GoBoard_size2)
{
   GameState Test(13);
   EXPECT_EQ(13, Test.GoBoardSize());
}

TEST(ConstructorTests, GoBoard_3by3)
{
   GameState Test(3);
   board testBoard = {
      { stone::empty, stone::empty, stone::empty },
      { stone::empty, stone::empty, stone::empty },
      { stone::empty, stone::empty, stone::empty } };
   EXPECT_EQ(testBoard, Test.GoBoard());
}

TEST(ConstructorTests, GoBoard_4by4)
{
   GameState Test(4);
   board testBoard = {
      { stone::empty, stone::empty, stone::empty, stone::empty },
      { stone::empty, stone::empty, stone::empty, stone::empty },
      { stone::empty, stone::empty, stone::empty, stone::empty },
      { stone::empty, stone::empty, stone::empty, stone::empty } };
   EXPECT_EQ(testBoard, Test.GoBoard());
}

TEST(PlacingStoneTests, Play_white_On_1_1)
{
   GameState Test(3);
   board testBoard = {
      { stone::empty, stone::empty, stone::empty },
      { stone::empty, stone::empty, stone::empty },
      { stone::empty, stone::empty, stone::empty } };
   EXPECT_EQ(testBoard, Test.GoBoard());
   Test.PlayStone(1, 1, stone::white);
   testBoard[1][1] = stone::white;
   EXPECT_EQ(testBoard, Test.GoBoard());
}

TEST(PlacingStoneTests, play_black_on_1_1)
{
   GameState Test(3);
   board testBoard = {
      { stone::empty, stone::empty, stone::empty },
      { stone::empty, stone::empty, stone::empty },
      { stone::empty, stone::empty, stone::empty } };
   EXPECT_EQ(testBoard, Test.GoBoard());
   Test.PlayStone(1, 1, stone::black);
   testBoard[1][1] = stone::black;
   EXPECT_EQ(testBoard, Test.GoBoard());
}

TEST(PlacingStoneTests, play_black_on_0_0_and_white_on_1_1)
{
   GameState Test(3);
   board testBoard = {
      { stone::empty, stone::empty, stone::empty },
      { stone::empty, stone::empty, stone::empty },
      { stone::empty, stone::empty, stone::empty } };
   EXPECT_EQ(testBoard, Test.GoBoard());
   Test.PlayStone(0, 0, stone::black);
   testBoard[0][0] = stone::black;
   Test.PlayStone(1, 1, stone::white);
   testBoard[1][1] = stone::white;
   EXPECT_EQ(testBoard, Test.GoBoard());
}