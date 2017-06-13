#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <set>
using namespace std;

struct Point
{
    double m_x;
    double m_y;

    Point() : m_x(0), m_y(0) {};
    Point(double x, double y) : m_x(x), m_y(y) {};
};

ostream& operator<< (ostream& outstream, const Point& P)
{
    cout << fixed << setprecision(3) << P.m_x << " " << P.m_y << endl;
    return outstream;
}

bool operator< (const Point& lhs, const Point& rhs)
{
    return (lhs.m_x < rhs.m_x || (lhs.m_x == rhs.m_x && lhs.m_y < rhs.m_y)); //op(a,b) and op(b,a) cannot both be true (but they would be if they were equal).
}

Point CalulateFourthPoint(const set<Point>& pointSet, const Point& dup)
{
    double x = 0.0, y = 0.0;
    for (auto& p : pointSet)
    {
        x += p.m_x;
        y += p.m_y;
    }
    return Point(x - 2 * dup.m_x, y - 2 * dup.m_y);
}

void test_case(stringstream input)
{
    set<Point> PointSet;
    Point duplicatePoint;

    for (int i = 0; i < 4 ; ++i)
    {
        Point tempPoint;
        input >> tempPoint.m_x >> tempPoint.m_y;
        auto result = PointSet.insert(tempPoint); //operator== is not used by std::set. Elements a and b are considered equal iff !(a < b) && !(b < a)

        if (result.second == false)
        {
            duplicatePoint = *result.first;
        }
    }

    cout << CalulateFourthPoint(PointSet, duplicatePoint);
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