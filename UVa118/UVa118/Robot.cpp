#include "Robot.h"
#include <iostream>
using namespace std;

Oritation& operator++(Oritation& now)
{
    unsigned int next = now + 1;
    if (next == 4)
    {
        next = 0;
    }
    now = static_cast<Oritation>(next);
    return now;
}

Oritation& operator--(Oritation& now)
{
    int next = now - 1;
    if (next == -1)
    {
        next = 3;
    }
    now = static_cast<Oritation>(next);
    return now;
}


Robot::Robot(const size_t x, const size_t y) 
: m_map_boundary(std::make_pair(x, y)) 
{ 

}

void Robot::SetInitPosition(const size_t x, const size_t y, const char orientation)
{
    m_position_now = std::make_pair(x, y);

    switch (orientation)
    {
    case 'N':
        m_orientation_now = North;
        break;
    case 'E':
        m_orientation_now = East;
        break;
    case 'S':
        m_orientation_now = South;
        break;
    case 'W':
        m_orientation_now = West;
        break;
    default:
        break;
    }
};

void Robot::SetInstruction(const std::string& instruction)
{
    m_Instruction = instruction;
}

void Robot::Go()
{
    for (char& command : m_Instruction)
    {
        if (!AdjustNextCommand(command))
        {
            cout << m_position_now.first << " " << m_position_now.second << " " << PrinOritation(m_orientation_now) << " LOST" << endl;
            m_ForbiddenInstruction.insert(make_pair(m_position_now, m_orientation_now));
            return;
        }
    }
    cout << m_position_now.first << " " << m_position_now.second << " " << PrinOritation(m_orientation_now) << endl;
    return;
}

bool Robot::MoveOneStep()
{
    if (m_ForbiddenInstruction.find(make_pair(m_position_now, m_orientation_now)) != m_ForbiddenInstruction.end())
    {
        return true;
    }

    std::pair<size_t, size_t> m_position_next(m_position_now);
    switch (m_orientation_now)
    {
    case North:
        ++m_position_next.second;
        break;
    case East:
        ++m_position_next.first;
        break;
    case South:
        --m_position_next.second;
        break;
    case West:
        --m_position_next.first;
        break;
    }

    if ((m_position_next.first > m_map_boundary.first) || (m_position_next.second > m_map_boundary.second))
    {
        return false;
    }
    else
    {
        m_position_now = m_position_next;
        return true;
    }
}

bool Robot::AdjustNextCommand(char input)
{
    switch (input)
    {
    case 'F': 
        return MoveOneStep();
    case 'R':
        ++m_orientation_now;
        return true;
    case 'L':
        --m_orientation_now;
        return true;
    default:
        return false;
    }
}

char Robot::PrinOritation(Oritation & input)
{
    switch (input)
    {
    case North:
        return 'N';
    case East:
        return 'E';
    case South:
        return 'S';
    case West:
        return 'W';
    default:
        return ' ';
    }
}