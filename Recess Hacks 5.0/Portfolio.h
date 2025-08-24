#pragma once
#include <vector>
#include "BankAccount.h"
#include "Investment.h"
class Portfolio {
public:
	std::vector<Investment> investments;

	void buyInvestment(Investment& inv, BankAccount& account);
	void sellInvestment(int index, BankAccount& account);
	void listInvestments();

};