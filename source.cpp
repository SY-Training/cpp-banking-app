#include "source.h"
#include <iostream>

int main()
{

    // Account management.
    //  > Create.
    //  > Delete.
    //  > Modify.
    // Deposit amount.
    // Withdraw amount.
    // Show balance.
    // List accounts.

    std::cout << "Hello there" << std::endl;
    return 0;
}

float DepositAmount(float amount)
{
    if (amount && amount > 0 && amount < 100000)
    {
        balance += amount;
        // Show Balance
    }

    if (amount && amount >= 100000)
    {
        std::cout << "Nice try, you wish!" << std::endl;
    }

    if (!amount)
    {
        InvalidAmount();
    }
}

float WithdrawAmount(float amount)
{
    if (amount && amount <= balance)
    {
        balance -= amount;
        // Show balance
    }
}

void ShowBalance()
{
    std::cout << "Your balance is\n\n£" << balance <<
}

void InvalidAmount()
{
    std::cout << "Invalid amount." << std::endl;
}