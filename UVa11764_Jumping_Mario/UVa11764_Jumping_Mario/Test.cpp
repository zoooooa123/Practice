#include "gtest/gtest.h"
#include "Mario.h"
#include <vector>
#include <utility>
using namespace std;

TEST(Mario, CalculateJumpUpAndDown)
{
    vector<unsigned int> jump = { 1,2,3,4,5 };
    EXPECT_EQ(make_pair(4, 0), Mario::CalculateJump(jump.begin()));
}