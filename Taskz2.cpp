#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

void Problem1() {
	/*Write and test a program which
	•Asks the user to enter three numbers;
	•Reads them in;
	•Then,
	–if preprocesor macro GETMAX is defined, writes the largest number on thescreen;
	–if preprocesor macro GETMIN is defined, writes the smallest number;
	–if both macros are defined, wites both the smallest and the largest numbers;
	–if none of them is defined, the compilation should fail.*/

}

void Problem2() {
	/*Write a program solving quadratic equations (ax2+bx+c= 0) 
	given the coefficients a,b and c. 
	The program should work in all cases 
	(in particular, when coefficients are 0 or the discriminant is negative).
	*/
    
    double a{}, b{}, c{}, x1{}, x2{};
    char ch;
    cout << "Enter the value of a: " << endl;
    cin >> a;
    cout << "Enter the value of b: " << endl;
    cin >> b;
    cout << "Enter the value of c: " << endl;
    cin >> c;
    cout << "The quadratic equation is: " << a;
    cout << "*x*x+" << b;
    cout << "*x+" << c << endl;

    if
        (a == 0 && b == 0)
        cout << "It's not a valid equation!" << endl;
    if
        (a == 0 && b != 0)
    {
        x1 = -(c / b);
        cout << endl;
        cout << "Root: " << x1;
        cout << endl;
    }
    if ((b * b - 4 * a * c) > 0)
    {
        x2 = (b * b) - (4 * a * c);
        x1 = -b + sqrt(x2);
        cout << "Root: " << x1 << endl;
    }
    if ((b * b - 4 * a * c) < 0)
    {
        cout << "There is no real root!" << endl;
    }
    system("pause");
}

void Problem3() {
	/*Write a program reading integers until zero is entered and printing 
	the length of the longest sequence of consecutive numbers of the same value (and this value).
	For example, for 22 22 22 22 3 3 3 2 -6 -6 -6 0
    the result should be Longest sequence: 
	4 times 22
	for-2 -2 -2 31 31 31 31 31 17 6 6 6 0
	the result should be Longest sequence: 
	5 times 31 and 
    for-3 2 -3 -3 2 -3 61 61 61 0
	it should be Longest sequence: 3 times 611
    Do not use arrays, strings or any other kind of collections.*/

    int input{}, longestLenght{ 1 }, longestNum{ input }, currentLenght{ 1 }, previousLenght{input};
    cout << "Enter a number: " << endl;
    cin >> input;

    while (input != 0) {
        cin >> input;

    }
}

void Problem4() {
    /*Write a program which reads in a loop a sequence of integral numbers until the userenters 0, 
    which just signals the end of data and is not then taken into account. 
    Afterthat, the program prints the value of the smallest and the largest element of the sequence 
    and the number of occurrences of these values in the whole sequence.For example, for the sequence (7,3,−24,2,7,−24,7,2,0), 
    the program should print:
    Min = -24 2 times
    Max = 7 3 times
    Note: do not use arrays or any other collections!*/


}

int gcdRec(int a, int b) {
    if (b == 0)
        return a;
    return gcdRec(b, a % b);
}

int sumDigits(int n) {
    int sum{ 0 };
    while (n != 0) {
        sum = sum + n % 10;
        n /= 10;
    }
    return sum;
}

int numDigits(int n) {
    int count{ 0 };
    while (n != 0)
    {
        n /= 10;
        ++count;
    }
    return count;
}

void printOddEven(int n) {
    if (n % 2 == 0)
        cout << "The number is even! " << endl;
    else
        cout << "The number is odd! " << endl;
}

void hailstone(int n) {

    if (n == 1) {
        return 1;
    }
    else if (n % 2 != 0)
    {
        n = 3 * n + 1;
        cout << n << endl;
    }
    else
    {
        n /= 2;
        cout << n << endl;
    }
    return hailstone(n);
}

int main()
{

    Problem2();
    
    cout << "gcdRec(12, 42) = " << gcdRec(12, 42) << endl << 
        "gcdRec(12, 25) = " << gcdRec(12, 25) << endl; 

    cout << "sumDigits(123) = " << sumDigits(123) << endl << 
        "sumDigits(971) = " << sumDigits(971) << endl; 

    cout << "numDigits(12345) = " << numDigits(12345) << endl << 
        "numDigits(971) = " << numDigits(971) << endl; 

    cout << "printOddEven(15): "; printOddEven(15); 
    cout << endl; cout << "printOddEven(14): "; printOddEven(14); 

    cout << endl; cout << "hailstone(13): "; hailstone(13); 
    cout << endl;
}
