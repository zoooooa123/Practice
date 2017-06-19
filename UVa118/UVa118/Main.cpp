#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

class Robot
{
public:
    Robot(const size_t x, const size_t y) : m_map_boundary(std::make_pair(x, y)) { }
    void SetInitPosition(const size_t x, const size_t y, const char orientation)
    {
        m_position_now = std::make_pair(x,y);
        m_orientation_now = orientation;
    };
    void SetInstruction(const std::string& instruction)
    {
        m_Instruction = instruction;
    };
    void Go() {  }

private:
    std::pair<size_t, size_t> m_map_boundary;
    std::pair<size_t, size_t> m_position_now;
    char m_orientation_now;
    std::string m_Instruction;
};

int main()
{
    using namespace std;
    size_t max_X, max_Y;
    stringstream ss;

    ss << cin.rdbuf();
    ss >> max_X >> max_Y;

    Robot CG(max_X, max_Y);

    while (!ss.eof())
    {
        size_t initX, initY;
        char orientation;
        string instruction;

        ss >> initX >> initY >> orientation;
        CG.SetInitPosition(initX, initY, orientation);
        ss >> instruction;
        CG.SetInstruction(instruction);
        CG.Go();
    }

    return 0;
}