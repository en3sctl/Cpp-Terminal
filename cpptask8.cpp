#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <functional>

struct Point
{
    double x;
    double y;
};

struct Rect
{
    Point a;
    Point b;
};

double area(Rect p) {
    return abs(p.b.x - p.a.x) * abs(p.b.y - p.a.y);
}

std::vector<double> process(const Rect* rects, size_t sz, std::function<double(Rect)> f)
{
    std::vector<double> vv;
    for (size_t i = 0; i < sz; ++i)
    {
        vv.push_back(f(rects[i]));
    }
    return vv;
}

//Problem2
enum Banks { PKO, BGZ, BRE, BPH };

struct Account {
    Banks   bank;
    int  balance;
};

struct Person {
    char name[20];
    Account account;
};

struct Couple {
    Person  he;
    Person she;
};

const Couple* bestClient(const Couple* cpls, int size, Banks bank) {
    if (cpls == nullptr || size <= 0) return nullptr;

    const Couple* richest{ nullptr };
    int max{ numeric_limits<int>::min() };

    for (int i{ 0 }; i < size; ++i)
    {
        if (cpls[i].he.account.bank == bank || cpls[i].she.account.bank == bank)
        {
            if (cpls[i].he.account.balance + cpls[i].she.account.balance > max)
            {
                richest = cpls + i;
                max = cpls[i].he.account.balance + cpls[i].she.account.balance;
            }
        }
    }
    return richest;
}

int main()
{
    //Problem1 Main
    Rect a[]{
        { {0,4}, {4,1} },
        { {-6,3}, {6,-2} },
        { {-7,4}, {8,-4} }
    };

    std::vector<double> v = process(a, std::size(a), area);

    for (auto e : v)
        std::cout << e << " ";
    return 0;

    //Problem2 Main
    using std::cout; using std::endl;
    Couple cpls[4] = {
            cpls[0] = { "Enes", PKO, 1200, "Ayse", BGZ, 1400 },
            cpls[1] = { "Jan", BGZ, 1400, "Suzy", BRE, -1500 },
            cpls[2] = { "Hubert", PKO, 1600, "Ula", BPH, 1500 },
            cpls[3] = { "Tom", BPH, 200, "Ela", BRE, -201 }
    };
    const Couple* p = bestClient(cpls, 4, BRE);
    if (p)
        cout << p->he.name << " and " << p->she.name
        << ": " << p->he.account.balance +
        p->she.account.balance << endl;
    else
        cout << "No such couple...\n";
}