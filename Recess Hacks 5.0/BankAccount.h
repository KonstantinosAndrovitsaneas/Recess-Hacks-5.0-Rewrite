#pragma once
class BankAccount {
public:
	double balance;

	BankAccount(double new_balance);


	void deposit(double amount);
	void withdraw(double amount);
	double get_balance();




};