#pragma once
#include <vector>
#include <utility>

class Mario 
{
public:
    static std::pair<int, int> CalculateJump(std::vector<unsigned int>::const_iterator iter)
    {
        return std::make_pair(0,0);
    }
};

bool operator==(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs)
{
    return lhs.first == rhs.first && lhs.second == rhs.second;
}


