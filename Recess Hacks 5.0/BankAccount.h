#pragma once
class BankAccount {
public:
	float balance;

	BankAccount(float new_balance);


	void deposit(float amount);
	void withdraw(float amount);
	float get_balance() const;




};