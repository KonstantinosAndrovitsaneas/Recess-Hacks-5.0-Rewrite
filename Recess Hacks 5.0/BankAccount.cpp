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

void BankAccount::withdraw(double amount) {
	if (amount > 0 && amount <= balance) {
		balance -= amount;
		std::cout << "Withdrew: $" << amount << std::endl;
	} else if (amount > balance) {
		std::cout << "Insufficient funds!" << std::endl;
	} else {
		std::cout << "Withdrawal amount must be positive!" << std::endl;
	}
}

double BankAccount::get_balance()  {
	return balance;
}	