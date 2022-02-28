#include <iostream>
using namespace std;

int main()
{
    short value1{ 30000 };
    short value2{ 10000 };
    int product{ value1 * value2 }; //When you put in the short variable here, you will get a linker error. It will be an overflow.

    cout << product << endl;

    return 0;
}
