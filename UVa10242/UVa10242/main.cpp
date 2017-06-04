#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct Point
{
    double x = 0.0;
    double y = 0.0;
};

ostream& operator >> (ostream& outstream, const Point& P)
{
    cout << P.x << " " << P.y << endl;
    return outstream;
}

void test_case(const string& input)
{
    Point p1,p2,p3,p4;
    stringstream ss(input);
    ss >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    vector<Point> allPoint = { p1, p2, p3, p4};
};

int main()
{
    string eachLine;
    while (getline(cin, eachLine))
    {
        test_case(eachLine);
    }
    return 0;
}