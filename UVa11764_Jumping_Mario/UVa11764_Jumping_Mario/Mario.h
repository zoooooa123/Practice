#pragma once
#include <vector>
#include <utility>
#include <iostream>
#include <string>

class Mario 
{
public:
    void SetInputGroupTimes() {std::cin >> m_RemainInputTimes;}
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

    static std::string ShowResult(unsigned int caseID, unsigned int higherTimes, unsigned int lowerTimes)
    {
        return "Case " + std::to_string(caseID) + ": " + std::to_string(higherTimes) + " " + std::to_string(lowerTimes);
    }

private:
    size_t m_RemainInputTimes;
};


