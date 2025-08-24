#include "Portfolio.h"
#include <iostream>
#include <vector>
#include "BankAccount.h"
void Portfolio::buyInvestment(Investment* inv, BankAccount& account) {
	bool bought = account.withdraw(inv->get_value());
	if(bought == true){
	investments.push_back(inv);
	}
	
	auto it = std::find(Investment::all_investments.begin(), Investment::all_investments.end(), inv);
	if (it != Investment::all_investments.end()) {
		Investment::all_investments.erase(it);
	}	



}

void Portfolio::sellInvestment(int index, BankAccount& account) {
	if (index >= 0 && index < investments.size()) {
		Investment* inv = investments[index];
		account.deposit(inv->get_value());
		

		Investment::all_investments.push_back(inv);
		investments.erase(investments.begin() + index);
		
	
	} else {
		std::cout << "This investment does not exist!" << std::endl;
	}
}

void Portfolio::listInvestments() {
	if (investments.size() > 0) {
		for (int i = 0; i <= investments.size()-1; i++) {

			std::cout << "Investment " << i + 1 << ": $" << investments[i]->get_value() << std::endl;
		}
	}
	else {
	
		std::cout << "You have no investments!" << std::endl;
	}
}