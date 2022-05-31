#include <iostream>
#include <cmath>
using namespace std;

//Problem1
class Point {
    double x, y;

public:
    Point()
    {
        this->x = 0;
        this->y = 0;
    };

    Point(double s)
    {
        this->x = s;
        this->y = s;
    };

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    };

    double getX() const
    {
        return this->x;
    };

    double getY() const
    {
        return this->y;
    };

    Point& setX(double xx)
    {
        this->x == xx;
        return *this;
    };

    Point& setY(double yy)
    {
        this->y == y;
        return *this;
    };

    Point& transX(double dx)
    {
        this->x = x + dx;
        return *this;
    };

    Point& transY(double dy)
    {
        this->y = y + dy;
        return *this;
    };

    Point& transXY(double dx, double dy)
    {
        this->x = x + dx;
        this->y = y + dy;
        return *this;
    };

    static double dist(const Point& p, const Point& q)
    {
        return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
    }
};

//Problem 2
class Rect {
private :
    double lenght, width;

public:
    Rect() 
    {
        this->lenght* this->lenght;
    }

    Rect(double x) 
    {
        this->width* x;
    }

    Rect(double x, double y);

    double getA() const
    {
        return this->lenght;
    }

    double getB() const
    {
        return this->width;
    }

    double getDiagonal()
    {
        return sqrt((lenght * lenght) + (width * width));
    }

    double getArea()
    {
        return lenght * width;
    }

    bool isLargerThan(const Rect&)
    {
        if (getArea() > )
        {
            return true;
        }
    }
};


int main()
{
    //Problem1 Main
    Point p;
    Point q(1);
    Point r(1, 2);
    p.transXY(5, 6);
    q.transX(-1).transY(-1).transXY(2, 2);
    r.setX(10).transY(-8);
    std::cout << Point::dist(p, q) << std::endl;
    std::cout << Point::dist(p, r) << std::endl;

    //Problem2 Main


    return 0;
}
