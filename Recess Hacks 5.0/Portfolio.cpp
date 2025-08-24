#include "Portfolio.h"
#include <iostream>
#include <vector>
#include "BankAccount.h"
void Portfolio::buyInvestment(Investment& inv, BankAccount& account) {
	account.withdraw(inv.get_value());
	investments.push_back(inv);
}

void Portfolio::sellInvestment(int index, BankAccount& account) {
	if (index >= 0 && index < investments.size()) {
		account.deposit(investments[index].get_value());
		
		investments.erase(investments.begin() + index);
	} else {
		std::cout << "This investment does not exist!" << std::endl;
	}
}