#include "source.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Account
{
    string AccountName;
    float AccountBalance;
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
    //  > Create. y
    //  > Delete. y
    //  > Modify. y
    // Deposit amount. y round up floats to 2 decimal places.
    // Withdraw amount. y
    // Show balance. y
    // List accounts. y

    cout << "Hello there" << endl;
    return 0;
}

void ShowBalance()
{
    cout << "\nYour balance is\n\n   £" << fixed << setprecision(2) << balance << endl;
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
    string accountName{"name"};
    float accountAmount{0.f};
    cout << "\nAccount name: \n"
         << endl;
    cin >> accountName;

    cout << "\nEnter balance for " << accountName << ": \n"
         << endl;
    cin >> accountAmount;

    if (!cin) // If cin fails (IE cin is not a float)
    {
        cin.clear();  // reset failbit.
        cin.ignore(); // ignore the input - prevents infinite error loop.
        cout << "\nERROR: balance MUST be a number" << endl;
    }

    if (accountName != "name" && accountAmount != 0)
    {
        Account newAcc = {accountName, accountAmount};
        accVec.push_back(newAcc);
    }

    else
    {
        cout << "ERROR. Either name or balance is undefined. Try again." << endl;
    }
}

void ModifyAccount()
{
    int accList{1};
    int selection;
    int selectVec;

    if (accVec.empty())
    {
        cout << "\nThere are no accounts to modify.\n"
             << endl;
    }

    else
    {
        for (int i = 0; i < accVec.size(); ++i)
        {
            cout << accList << ". " << accVec[i].AccountName << "\n"
                 << endl;
            ++accList;
        }

        cout << "Select the number of the account you wish to modify.\n"
             << endl;
        cin >> selection;
        if (!cin)
        {
            cin.clear();
            cin.ignore();
            cout << "\nERROR: inout MUST be a number" << endl;
        }

        selectVec = selection - 1;

        if (selectVec >= 0 && selectVec <= accVec.size())
        {

            // can edit name or amount.
            int nameORbalance{0};

            cout << "Do you wish to edit the:\n"
                    "1. Account name.\n"
                    "2. Account balance.\n"
                    "Choose a number: "
                 << endl;

            cin >> nameORbalance;
            if (!cin)
            {
                cin.clear();
                cin.ignore();
                cout << "\nERROR: input MUST be a number" << endl;
            }

            if (nameORbalance == 1)
            {
                cout << "Enter a new balance: " << endl;
                float newBalance{0};
                cin >> newBalance;
                if (!cin)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "\nERROR: input MUST be a number" << endl;
                }

                accVec[selectVec].AccountBalance = newBalance;
            }

            else if (nameORbalance == 2)
            {
                cout << "Enter a new name: " << endl;
                string newName{"name"};
                cin >> newName;
                accVec[selectVec].AccountName = newName;
            }

            else
            {
                cout << "you  must chose 1 or 2.\n"
                     << endl;
            }
        }
        else
        {
            cout << "That is not an available option.\n"
                 << endl;
        }
    }
}

void DeleteAccount()
{
    int accList{1};
    int selection;
    int selectVec;

    if (accVec.empty())
    {
        cout << "\nThere are no accounts to delete." << endl;
    }

    else
    {
        for (int i = 0; i < accVec.size(); ++i)
        {
            cout << accList << ". " << accVec[i].AccountName << "\n"
                 << endl;
            ++accList;
        }

        cout << "\nSelect the number of the account you wish to delete.\n"
             << endl;
        cin >> selection;
        if (!cin)
        {
            cin.clear();
            cin.ignore();
            cout << "\nERROR: inout MUST be a number" << endl;
        }

        selectVec = selection - 1;

        if (selectVec >= 0 && selectVec <= accVec.size())
        {
            cout << "Are you sure you wish to delete " << accVec[selectVec].AccountName << "? y/n\n"
                 << endl;

            char yORn;
            cin >> yORn;
            if (!cin)
            {
                cin.clear();
                cin.ignore();
                cout << "\nERROR: inout MUST be a number" << endl;
            }

            if (yORn == 'y')
            {
                accVec.erase(accVec.begin() + selectVec);
            }

            else if (yORn)
            {
            }

            else
            {
                cout << "you must type y or n.\n"
                     << endl;
            }
        }
        else
        {
            cout << "\nThat is not an available account.\n"
                 << endl;
        }
    }
}

void ListAccounts()
{
    for (int i = 0; i < accVec.size(); i++)
    {
        cout << "\n"
             << accVec[i].AccountName << "\n"
             << accVec[i].AccountBalance << "\n\n"
             << endl;
    }
}

void Landing()
{
    int choice{0};

    cout << "\nChoose and option:\n\n"
            "1. Show balance.\n"
            "2. Deposit amount.\n"
            "3. Withdraw amount.\n"
            "4. Create an account.\n"
            "5. Modify an account.\n"
            "6. List accounts.\n"
            "7. Delete an account.\n"
         << endl;

    cin >> choice;

    if (!cin)
    {
        cin.clear();
        cin.ignore();
        cout << "\nERROR: Please select a number.\n"
             << endl;
    }

    else
    {
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
            ModifyAccount();
            break;
        case 6:
            ListAccounts();
            break;
        case 7:
            DeleteAccount();
            break;
        default:
            cout << "Invalid. Please select an option 1 - 6.";
            break;
        }
    }
}
