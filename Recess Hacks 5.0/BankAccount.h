#pragma once
class BankAccount {
public:
	double balance;

	BankAccount(double new_balance);


	void deposit(double amount);
	bool withdraw(double amount, bool isSalary);
	double get_balance();
};