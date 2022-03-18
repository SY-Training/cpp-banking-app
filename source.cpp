#include "source.h"
#include <iostream>

using namespace std;

void ShowBalance()
{
    cout << "\nYour balance is\n\n   £" << balance << endl;
}

void InvalidAmount()
{
    cout << "\nInvalid amount.\n"
         << endl;
}

void DepositAmount()
{
    float amount{0};

    cout << "\nSelect amount to deposit:\n\n"
         << endl;
    cin >> amount;

    if (amount > 0 && amount < 100000)
    {
        balance += amount;
        ShowBalance();
    }

    if (amount >= 100000)
    {
        cout << "\nNice try, you wish!\n"
             << endl;
    }

    else
    {
        InvalidAmount();
    }
}

void WithdrawAmount()
{
    float amount{0};

    cout << "\nSelect amount to withdraw:\n\n"
         << endl;
    cin >> amount;

    if (amount <= balance)
    {
        balance -= amount;
        ShowBalance();
    }

    else
    {
        InvalidAmount();
    }
}

void Landing()
{
    // options
    int choice{0};

    cout << "\nChoose and option:\n\n"
            "1. Show balance.\n"
            "2. Deposit amount.\n"
            "3. Withdraw amount.\n"
            "4. Create an account.\n"
            "5. Modify an account.\n"
            "6. Delete an account.\n"
         << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        ShowBalance();
        break;
    case 2:
        DepositAmount();
        break;
    case 3:
        WithdrawAmount();
        break;
    case 4:
        // Create account
        break;
    case 5:
        // Modify account
        break;
    case 6:
        // Delete account
        break;
    default:
        cout << "Invalid. Please select an option 1 - 6.";
        break;
    }
}

int main()
{

    // TODO put move functions into seperate files and call via headers.
    while (inApp)
    {
        Landing();
    }
    // Account management.
    //  > Create.
    //  > Delete.
    //  > Modify.
    // Deposit amount.
    // Withdraw amount.
    // Show balance.
    // List accounts.

    cout << "Hello there" << endl;
    return 0;
}