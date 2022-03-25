#include "source.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Account
{
    std::string AccountName;
    int AccountBalance;
};

vector<Account> accVec;

int main()
{

    // TODO put move functions into seperate files and call via headers.
    while (inApp)
    {
        Landing();
    }
    // Account management.
    //  > Create. n
    //  > Delete. n
    //  > Modify. n
    // Deposit amount. y
    // Withdraw amount. y
    // Show balance. y
    // List accounts. n

    cout << "Hello there" << endl;
    return 0;
}

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

    else if (amount >= 100000)
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

void CreateAccount()
{
    std::string accountName{"name"};
    int accountAmount{0};
    cout << "\nAccount name: \n"
         << endl;
    cin >> accountName;

    cout << "\nEnter balance for " << accountName << ": \n"
         << endl;
    cin >> accountAmount;

    // put into account array.
    Account newAcc = {accountName, accountAmount};
    // put into array. May need to use vectors.
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
        CreateAccount();
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
