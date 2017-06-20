#pragma once
#include <string>
#include <utility>

enum Oritation
{
    North,
    East,
    South,
    West,
};

class Robot
{
public:
    Robot(const size_t x, const size_t y);
    void SetInitPosition(const size_t x, const size_t y, const char orientation);
    void SetInstruction(const std::string& instruction);
    void Go();
    bool MoveOneStep();
    bool AdjustNextCommand(char input);

private:

    char PrinOritation(Oritation& input);
    std::pair<size_t, size_t> m_map_boundary;
    std::pair<size_t, size_t> m_position_now;
    Oritation m_orientation_now;
    std::string m_Instruction;
};