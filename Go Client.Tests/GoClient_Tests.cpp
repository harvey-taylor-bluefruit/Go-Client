#include "gtest/gtest.h"
#include "Go Client.h"

TEST(goBoard, testing_tests)
{
	GoBoard Test(1);
	EXPECT_EQ(1, Test.ReturnGoBoardSize());
}