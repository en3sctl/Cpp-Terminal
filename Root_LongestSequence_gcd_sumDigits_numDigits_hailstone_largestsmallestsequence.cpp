#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void Problem2()
{
    /*Write a program solving quadratic equations (ax2+bx+c= 0)
    given the coefficients a,b and c.
    The program should work in all cases
    (in particular, when coefficients are 0 or the discriminant is negative).
    */

    float a {}, b {}, c {}, x1 {}, x2 {}, discriminant, real_part, imaginary_part;
    cout << "Enter the coefficients starting with a, b and c: " << endl;
    cin >> a >> b >> c;
    discriminant = b * b - 4 * a * c;

    if(discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);

        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
    } else if(discriminant == 0) {
        cout << "Roots are real and same!" << endl;
        x1 = -b / (2 * a);
        cout << "x1 = x2 = " << x1 << endl;
    } else {
        real_part = -b / (2 * a);
        imaginary_part = sqrt(-discriminant) / (2 * a);
        cout << "Roots are different: " << endl;
        cout << "x1: " << real_part << "+" << imaginary_part << "i" << endl;
        cout << "x2: " << real_part << "-" << imaginary_part << "i" << endl;
    }
}

void Problem3()
{
    /*Write a program reading integers until zero is entered and printing
    the length of the longest sequence of consecutive numbers of the same value (and this value).
    For example, for 22 22 22 22 3 3 3 2 -6 -6 -6 0
    the result should be Longest sequence:
    4 times 22
    for -2 -2 -2 31 31 31 31 31 17 6 6 6 0
    the result should be Longest sequence:
    5 times 31 and
    for -3 2 -3 -3 2 -3 61 61 61 0
    it should be Longest sequence: 3 times 61
    Do not use arrays, strings or any other kind of collections.*/

    int input {}, countMax { 1 }, count { 1 };
    cout << "Enter a number: ";
    cin >> input;
    int max = input;

    while(input != 0) {
        int temporary_number = input;
        cout << "Enter a number: ";
        cin >> input;
        if(temporary_number == input) {
            count++;
            if(count > countMax) {
                countMax = count;
                max = input;
            }
        } else
            count = 1;
    }
    cout << "The longest sequence is: " << countMax << " times " << max << endl;
}

void Problem4()
{
    /*Write a program which reads in a loop a sequence of integral numbers until the user enters 0,
    which just signals the end of data and is not then taken into account.
    After that, the program prints the value of the smallest and the largest element of the sequence
    and the number of occurrences of these values in the whole sequence.
    For example, for the sequence (7,3,−24,2,7,−24,7,2,0),
    the program should print:
    Min = -24 2 times
    Max = 7 3 times
    Note: do not use arrays or any other collections!*/

    int numUserInt, integers, number, maxNumber = 0, minNumber = 0, counter = 0;

    // Get the number of integers
    cout << "How many integers would you like to enter?" << endl;
    cin >> numUserInt;
    cout << "Please enter " << numUserInt << " integers." << endl;

    integers = 1;

    while(integers <= numUserInt) {
        cin >> number;

        if(integers == 1)
            maxNumber = minNumber = number;

        if(number > maxNumber)
            maxNumber = number;

        if(number < minNumber)
            minNumber = number;

        integers++;
        counter; // i couldnt implement that.
    }
    cout << "Max: " << maxNumber << ", " << counter << " times." << endl;
    cout << "Min: " << minNumber << ", " << counter << " times." << endl;
}

int gcdRec(int a, int b)
{
    if(b == 0)
        return a;
    return gcdRec(b, a % b);
}

int sumDigits(int n)
{
    int sum { 0 };
    while(n != 0) {
        sum = sum + n % 10;
        n /= 10;
    }
    return sum;
}

int numDigits(int n)
{
    int counter { 0 };
    while(n != 0) {
        n /= 10;
        ++counter;
    }
    return counter;
}

void printOddEven(int n)
{
    if(n % 2 == 0)
        cout << "The number is even." << endl;
    else
        cout << "The number is odd." << endl;
}

void hailstone(int n)
{
    if(n == 1) {
        n = 1;
    } else if(n % 2 != 0) {
        n = 3 * n + 1;
        cout << n << endl;
    } else {
        n /= 2;
        cout << n << endl;
    }
    return hailstone(n);
}

int main()
{
    Problem2();
    Problem3();
    Problem4();

    cout << "gcdRec(12, 42) = " << gcdRec(12, 42) << endl
              << "gcdRec(12, 25) = " << gcdRec(12, 25) << endl;
    cout << "sumDigits(123) = " << sumDigits(123) << endl
              << "sumDigits(971) = " << sumDigits(971) << endl;
    cout << "numDigits(12345) = " << numDigits(12345) << endl
              << "numDigits(971) = " << numDigits(971) << endl;
    cout << "printOddEven(15): ";
    printOddEven(15);
    cout << std::endl;
    cout << "printOddEven(14): ";
    printOddEven(14);
    cout << std::endl;
    cout << "hailstone(13): ";
    hailstone(13);
    cout << std::endl;
}
