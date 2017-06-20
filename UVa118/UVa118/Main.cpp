#include <iostream>
#include <sstream>
#include <string>
#include "Robot.h"

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