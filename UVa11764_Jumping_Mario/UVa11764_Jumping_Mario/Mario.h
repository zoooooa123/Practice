#pragma once
#include <vector>
#include <utility>
#include <iostream>

class Mario 
{
public:
    static std::pair<int, int> CalculateJump(std::vector<unsigned int> &jump)
    {
        return std::make_pair(0,0);
    }
};

bool operator==(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
{
    return lhs.first == rhs.first && lhs.second == rhs.second;
}


