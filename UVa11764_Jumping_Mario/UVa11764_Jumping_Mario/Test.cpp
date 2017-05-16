#include "gtest/gtest.h"
#include "Mario.h"
#include <vector>
#include <utility>
using namespace std;

TEST(Mario, CalculateJumpUpAndDown)
{
    vector<unsigned int> jump1 = { 1,4,2,2,3,5,3,4 };
    EXPECT_EQ(make_pair(4, 2), Mario::CalculateJump(jump1));

    vector<unsigned int> jump2 = { 9 };
    EXPECT_EQ(make_pair(0, 0), Mario::CalculateJump(jump2));

    vector<unsigned int> jump3 = { 1,2,3,4,5 };
    EXPECT_EQ(make_pair(4, 0), Mario::CalculateJump(jump3));
}

TEST(Mario, ShowResult)
{
    EXPECT_EQ("Case 1: 4 2", Mario::ShowResult(1, 4, 2));
    EXPECT_EQ("Case 2: 0 0", Mario::ShowResult(2, 0, 0));
    EXPECT_EQ("Case 3: 4 0", Mario::ShowResult(3, 4, 0));
}