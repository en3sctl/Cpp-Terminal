#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <functional>
using namespace std;

//Problem1
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

    const Couple* richest { nullptr };
    int max {std::numeric_limits<int>::min()};

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

//Problem3
struct Node {
    int data;
    Node* next;
};

bool add(Node*& head, int data)
{
    Node* current = head;

    while (current != NULL) {
        if (current->data == data)
            return false;
        current = current->next;
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;

    return true;
}

size_t size(const Node* head);

void clear(Node*& head)
{
    Node* number;
    number = head;
    while (number->next != nullptr)
    {
        head = number->next;
        delete number;
    }
}

void printList(const Node* head)
{
    for (; head; head = head->next)
    {
        cout << head->data << " ";
    }
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

    cout << endl;

    //Problem2 Main
    using std::cout; using std::endl;
    Couple cpls [4] = {
            cpls[0] = { "Johny", PKO, 1200, "Mary", BGZ, 1400 },
            cpls[1] = { "Peter", BGZ, 1400, "Lucy", BRE, -1500 },
            cpls[2] = { "Kevin", PKO, 1600, "Lucy", BPH, 1500 },
            cpls[3] = { "Kenny", BPH, 200, "Lucy", BRE, -201 }
    };
    const Couple* p = bestClient(cpls, 4, BRE);
    if (p)
        cout << p->he.name << " and " << p->she.name
        << ": " << p->he.account.balance +
        p->she.account.balance << endl;
    else
        cout << "No such couple...\n";

    //Problem3 Main
    using std::cout; using std::endl;
    int tab[] = { 1,4,1,3,5 };
    Node* head = 0;
    for (size_t i = 0, e = std::size(tab); i != e; ++i) {
        bool b = add(head, tab[i]);
        cout << tab[i] << (b ? " " : " NOT ")
            << "added" << endl;
    }
    cout << "Size of the list: " << size(head) << endl;
    printList(head);
    clear(head);

    return 0;
}

