#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

struct Point
{
    double x;
    double y;
};

void CalulateFourthPoint( const Point& first, const Point& second, const Point& third)
{
    double x = 0.0, y = 0.0;
}

ostream& operator >> (ostream& outstream, const Point& P)
{
    cout << P.x << " " << P.y << endl;
    return outstream;
}

void test_case(stringstream input)
{
    vector<Point> vecPoint(4, Point());
    for (Point& p : vecPoint)
    {
        input >> p.x >> p.y;
    }

    set<Point> setPoint;
    for (Point& p : vecPoint)
    {
        if (setPoint.find(p) != setPoint.end());
    }
};

int main()
{
    string eachLine;
    while (getline(cin, eachLine))
    {
        test_case(stringstream(eachLine));
    }
    return 0;
}