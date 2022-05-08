#include <iostream>
#include <utility> // swap (may be useful)
#include <string>
using namespace std;

//Problem1
template<typename T>
T getMaxRecur(const T* arr, size_t size) 
{
    if (size == 1)
        return arr[0];
    return max(arr[size - 1], getMaxRecur(arr, size - 1));
}

//Problem2
template<typename T>
void pointerSort(const T* arr, const T** ptrs, size_t size) 
{
    int flag = 1;

    for (int i = size - 1; i > 0 && flag; i--)
    {
        flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (*ptrs[j] > *ptrs[j + 1])
            {
                arr = ptrs[j];
                ptrs[j] = ptrs[j + 1];
                ptrs[j + 1] = arr;
                flag = 1;
            }
        }
    }
}

template <typename T>
void printArrPointer(const T** parr, size_t size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << *parr[i] << " ";
    cout << endl;
}

int main() {

    //Problem1 Main
    using std::cout; using std::endl; using std::string;

    double ad[]{ 2.5, 9.1, 4.5, -1.0 };
    cout << "ad: " << getMaxRecur(ad, 4) << "; ";

    int    ai[]{ 2, 11, 5, 1, 9 };
    cout << "ai: " << getMaxRecur(ai, 5) << "; ";

    string as[]{ "Ala", "Ela", "Ula", "Ola" };
    cout << "as: " << getMaxRecur(as, 4) << endl;

    //Problem2 Main
    int arri[]{ -3, 4, 8, 3 };
    const int* parri[std::size(arri)];
    pointerSort(arri, parri, std::size(arri));
    printArrPointer(parri, std::size(parri));

    std::string arrs[]{ "Ela", "Ula", "Ala", "Ola" };
    const std::string* parrs[std::size(arrs)];
    pointerSort(arrs, parrs, std::size(arrs));
    printArrPointer(parrs, std::size(parrs));
}
