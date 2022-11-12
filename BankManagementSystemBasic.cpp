#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

class bank
{
    char name[100], address[100], y;
    float balance;
public:
    void openAccount();
    void depositMoney();
    void withdrawMoney();
    void displayAccount();
};

void bank::openAccount()
{
    cout << "Enter your full name: ";
    cin.ignore();
    cin.getline(name, 100);
    cout << "Enter your address: ";
    cin.ignore();
    cin.getline(address, 100);
    cout << "What type of account you want to open saving (s) or current (c) ?";
    cin >> y;
    cout << "Enter amount for deposit: ";
    cin >> balance;
    cout << "Your account is created \n";
}

void bank::depositMoney()
{
    int amountDeposit;
    cout << "Enter how much you want to deposit: ";
    cin >> amountDeposit;
    balance += amountDeposit;
    cout << "Total amount you deposit: " << balance;
}

void bank::displayAccount()
{
    cout << "Your full name: " << name;
    cout << "Your address: " << address;
    cout << "Type of account: " << y;
    cout << "Amount you deposit: " << balance << endl;
}

void bank::withdrawMoney()
{
    float amountWithdraw;
    cout << "Enter how much you want to withdraw: ";
    cin >> amountWithdraw;
    balance = balance - amountWithdraw;
    cout << "Total amount you left: " << balance << endl;
}

int main()
{
    int choice, x;
    bank object;
    do
    {

        cout << "1) Open account \n";
        cout << "2) Deposit money \n";
        cout << "3) Withdraw money \n";
        cout << "4) Display account \n";
        cout << "5) Exit \n";
        cout << "Select the option from list: \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "1) Open account \n";
            object.openAccount();
            break;
        case 2:
            cout << "2) Deposit \n";
            object.depositMoney();
            break;
        case 3:
            cout << "3) Withdraw \n";
            object.withdrawMoney();
            break;
        case 4:
            cout << "4) Display account \n";
            object.displayAccount();
        case 5:
            if (choice == 5) {
                exit(1);
            }
        default:
            cout << "This is not exist try again \n";
        }
        cout << "Do you want to select next option then press ::  y \n";
        cout << "If you want to exit then press :: N \n";

        x = _getch();
        if (x == 'n' || x == 'N')
            exit(0);

    } while (x == 'y' || x == 'Y');

    _getch();
    return 0;
}
