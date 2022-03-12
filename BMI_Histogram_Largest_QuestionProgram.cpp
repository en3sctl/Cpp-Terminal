#include <cmath>
#include <iostream>
using namespace std;

void problem1()
{
    /*Problem 1
     * Write a program which asks the user to enter his/her height (in meters, as double)
     * and the weight (in kilograms, also as a double).
     * Then the program should printhis/her BMI coefficient (body mass index)
     * defined as the weight in kilograms divided by the square of height in meters
     * — this number should come out close to 20*/

    double weight {}, height {};
    cout << "Please Enter Your Height: " << endl;
    cin >> height;
    cout << "Please Enter Your Weight: " << endl;
    cin >> weight;

    double bmi = weight / (height * height);
    cout << "Your BMI is : " << bmi << endl;
}
void problem2()
{
    /*Problem 2
     * Write a program which reads from the user three non-negative integers and then prints,
     * using symbols ’*’, a ‘histogram’ of the data represented by the numbers,
     * i.e.,three vertical bars, aligned at the bottom, with heights equal to the values of the three numbers.
     Do not use arrays, strings or any other kind of collections.*/

    int number1 {}, number2 {}, number3 {}, max { 0 };
    cout << "Please Enter Three Number For Your Histogram: " << endl;
    cin >> number1 >> number2 >> number3;

    if(number1 > max)
        max = number1;
    if(number2 > max)
        max = number2;
    if(number3 > max)
        max = number3;

    for(int i = max; i > 0; --i) {
        if(i > number1) {
            cout << " ";
        } else {
            cout << "*";
        }
        if(i > number2) {
            cout << " ";
        } else {
            cout << "*";
        }
        if(i > number3) {
            cout << " ";
        } else {
            cout << "*";
        }
        cout << endl;
    }
}
void problem3()
{

    /*Problem 3
     * Write a program which asks the user, in a loop, to enter a positive integer until the user enters 0.
     * Then the program prints one number from those which have been readin —
     * the one for which the sum of digits is the largest (and this sum of digits).
     * Example of a run of the program:
     * enter a natural number (0 if done): 1111
     * enter a natural number (0 if done): 82
     * enter a natural number (0 if done): 7890
     * enter a natural number (0 if done): 98
     * enter a natural number (0 if done): 1111119
     * enter a natural number (0 if done): 0
     * Max sum of digits was 24 for 7890
     * Note: Do not use arrays, strings and any other kind of collection.*/

    int number { 5 }, sum {}, largest {}, test_number {}, s;

    while(number != 0) {

        cout << "Please enter a natural number(0 if done): ";
        cin >> number;
        test_number = number;
        s = 0;

        while(test_number != 0) {
            s += test_number % 10;
            test_number /= 10;
        }
        if(s > sum) {
            largest = number;
            sum = s;
        }
    }
    cout << "Max sum of digits was " << sum << " for " << largest << endl;
}
void problem4()
{
    /*Problem4
     * Write a program which plays the ‘20 Questions’ game with the user.
     * The user chooses(in his/her mind) a number from the interval[1,1 000 000].
     * The program asks in a loop Is this n?, and the user responds with a letter

     •s(as in small) if n is smaller than the chosen number;
     •b(as in big) if n is bigger than the chosen number;
     •y(as in yes) if n is equal to the chosen number;
     * At the end the program should print something like

     * Number that you think of is ...
     * and provide the correct answer and number of trials.

     * Do not use arrays, strings orany other kind of collections.
     * The program should guarantee the correct answer after at most 20 questions.*/

    int num {}, guess {}, tries { 0 }, change_range = 500000;
    float inc_or_dec = 250000;
    char answer;
    cout << "Please choose a number from the interval [1, 1000000]: " << endl;
    cin >> num;

    while(20 > tries++) {
        cout << "If " << change_range << " is " << endl;
        cout << "smaller than the number you choose press s" << endl;
        cout << "greater than the number you choose press b" << endl;
        cout << "the number you choose press y" << endl;
        cin >> answer;
        if(answer == 's') {
            change_range -= inc_or_dec;
        }
        if(answer == 'b') {
            change_range += inc_or_dec;
        }
        if(answer == 'y') {
            guess = change_range;
            break;
        }
        inc_or_dec = round(inc_or_dec / 2);
    }
    cout << "The number you selected: " << guess << " and the number of trials: " << tries << endl;
}

int main()
{
    problem1();
    problem2();
    problem3();
    problem4();
