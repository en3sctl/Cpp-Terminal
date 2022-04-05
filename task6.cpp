#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Problem1 
unsigned short encode(int sex, int marit, int age, int edu, int place, int region, int answer) 
{

}

void info(unsigned short code) 
{

}

//Problem2
bool sumOfTwo(const std::vector<int>& v, int val, int& i, int& j) 
{
    std::vector<int> a{ 2, 4, 5, 8, 9, 11, 13, 15 };
    val = 21; //e.g
    for (int k = 0; k < a.size(); k++) {
        if (a.at(i) + a.at(j) > val)
            return true;
        else
            return false;
        i = 0;
        j = 0;
    }
}

//Problem3
bool isPrime(int n)
{
    for (int i(2); i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool allDiff(const int arr[], size_t sz)
{
    for(unsigned i = 0; i < sz; i++)
        for(unsigned j = i+1; j < sz; j++)
            if (arr[i] == arr[j]) {
                return false;
            }
    return true;
}

bool allDiff(const std::vector<int>& vec)
{
    if (vec.size() == 0) {
        return false;
    }
    return std::equal(vec.begin() + 1, vec.end(), vec.begin());
}

int numDiff(const int arr[], size_t sz)
{
    if (sz == 1)
        return -1;

    if (sz == 2)
        return 0;

    if (arr[0] == arr[1] && arr[0] != arr[2])
        return 2;
    if (arr[0] == arr[2] && arr[0] != arr[1])
        return 1;
    if (arr[1] == arr[2] && arr[0] != arr[1])
        return 0;

    for (int i = 3; i < sz; i++)
        if (arr[i] != arr[i - 1])
            return i;

    return -1;
}

int numDiff(const std::vector<int>& vec)
{
    
}

int fillWithPrimes(int arr[], size_t sz)
{
    for (int i = 2, j = 0; j < sz; ++i) {
        if (isPrime(i))
            arr[j++] = i;
    }
    //return arr[arr.lenght() -1];
}

int fillWithPrimes(std::vector<int>& vec)
{

}

int fillGaps(int arr[], size_t sz)
{

}

int fillGaps(std::vector<int>& vec)
{

}

size_t blockRem(int arr[], size_t sz, size_t from, size_t to)
{

}

size_t blockRem(std::vector<int>& vec, size_t from, size_t to)
{

}





int main()
{
    cout << sumOfTwo;
    //Problem3 Main
    

    return 0;
}

