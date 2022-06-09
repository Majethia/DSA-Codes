#include <vector>


class point
{
public:
    int x;
    int y;

    point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }

    point()
    {
        x = -1;
        y = -1;
    }
    friend bool operator== (const point& p1, const point& p2);
};

bool operator== (const point& p1, const point& p2)
{
    if (p1.x == p2.x && p1.y == p2.y)
    {
        return true;
    }
    return false;
}


struct solution
{
    std::vector<point> sol;
};


std::vector<solution> res;