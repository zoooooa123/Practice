#pragma once
#include <vector>
#include <utility>
#include <iostream>

class Mario 
{
public:
    static std::pair<int, int> CalculateJump(std::vector<unsigned int> &jump)
    {
        int higherTimes = 0, lowerTimes = 0;
        unsigned int prevJumpHeight = jump[0];

        for (unsigned int now : jump)
        {
            if (now > prevJumpHeight)
            {
                ++higherTimes;
            }
            else if (now < prevJumpHeight)
            {
                ++lowerTimes;
            }
            prevJumpHeight = now;
        }
        return std::make_pair(higherTimes, lowerTimes);
    }
};


