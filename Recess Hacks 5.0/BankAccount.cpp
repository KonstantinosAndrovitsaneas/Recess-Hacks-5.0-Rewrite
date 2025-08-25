#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(double new_balance) : balance(new_balance) {}


void BankAccount::deposit(double amount) {
	if (amount > 0) {
		balance += amount;
		std::cout << "Deposited: $" << amount << std::endl;
	} else {
		std::cout << "Deposit amount must be positive!" << std::endl;
	}
}

bool BankAccount::withdraw(double amount, bool isSalary) {
    if (amount <= 0) {
        std::cout << "Withdrawal amount must be positive!" << std::endl;
        return false;
    }

    if (amount <= balance) {
        balance -= amount;
        std::cout << "Withdrew $" << amount << std::endl;
        return true;
    }

    if (isSalary && amount > balance) {
        std::cout << "Could not pay worker salaries! Game Over." << std::endl;
        balance = 0;
        exit(0); 
    }
    else {
        std::cout << "Insufficient funds!" << std::endl;
    }

    return false;
}


double BankAccount::get_balance()  {
	return balance;
}