#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <ctime>
#include <utility>
using namespace std;

//Problem1
template <typename T>
T getSmallestValue(T t[], size_t size);

template <typename T>
T getSmallestValue(T t[], size_t size)
{
    int min, temp;
    int i = 0;
    temp = i;
    min = t[i];

    while (i < size)
    {
        if (min > t[i])
        {
            min = t[i];
            temp = i;
        }
        i++;
    }
    return temp;
}

template <typename T>
T getLargestValue(T t[], size_t size);

template <typename T>
T getLargestValue(int t[], size_t size)
{
    int max, temp;
    int i = 0;
    temp = i;
    max = t[i];

    while (i < size)
    {
        if (max < t[i])
        {
            max = t[i];
            temp = i;
        }
        i++;
    }
    return temp;
}

//Problem2
using std::vector;
using std::function;

template <typename T, typename FunType>
vector<T> filter(const vector<T>& v, FunType p) {
    v lambda1(v a)
        for (int i = 0; v.size; i++)
        {
            if (v[i] % 2 == 0)
                cout << v[i];
        }
        
    for (int i = 0; v.size; i++)
    {
        if (v[i] >= 0)
            cout << v[i];
        }
}

template <typename T, typename FunType1, typename FunType2>
vector<T> transfilt(vector<T>& v, FunType1 t, FunType2 p) {
    for (int i = 0; v.size; i++)
    {
        cout << sin(v[i])
    }

    for (int i = 0; v.size; i++)
    {
        if (v[i] <= mx && v[i] >= mn)
            cout << v[i];
    }
}

template <typename T>
void printVec(const vector<T>& v) {
    int i = 0;
    
    while (v.size() > 0)
    {
        cout << v[i];
        cout << " ";
        i += 1;
    }
}

//Problem3
template < typename T, typename FUN>
size_t part(T * arr, size_t size, FUN f) {
    // ...

}

template < typename T>
void printTab(const T * t, size_t size) {
    // ...
        
}
bool isEven(int e) { 
    return e % 2 == 0; 
}


int main()
{
    //Problem1 Main
    int integers[5];
    double doubles[5];
    string strings[5];

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            switch (j)
            {
            case 0:
                cout << "Please Enter Integers: " << i + 1 << " ";
                cin >> integers[i];
                break;
            case 1:
                cout << "Please Enter Doubles: " << i + 1 << " ";
                cin >> doubles[i];
                break;
            case 2: 
                cout << "Please Enter Strings: " << i + 1 << " ";
                cin >> strings[i];
                break;
            }
        }
    }

    //Problem2 Main
    vector<int> v{ 1, -3, 4, -2, 6, -8, 5 };
    printVec(v);
    vector<int> r = filter(v, lambda1);
    printVec(r);
    vector<int> s = filter(v, /* lambda_2 */);
    printVec(s);
    vector<double> w{ 1.5, -3.1, 4.0, -2.0, 6.3 };
    printVec(w);
    double mn = -0.5, mx = 0.5;
    vector<double> d =
        transfilt(w, /* lambda_3*/ , /* lambda_4 */);
    printVec(w);
    printVec(d);

}
