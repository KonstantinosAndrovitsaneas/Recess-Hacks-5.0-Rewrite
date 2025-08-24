#include "Events.h"
#include <iostream>

std::vector<Events*> Events::simple_events;

Events::Events(double amount, std::string message) : amount(amount), messag(message) {
	simple_events.push_back(this);

}

void Events::simple_event(BankAccount& account, Portfolio& portfolio) {
	std::cout << messsage;
	if (amount > account.balance()) {
		amount = account.balance();
		account.withdraw(amount);
	}
	else {
		account.withdraw(amount);
	}
}


void Events::complex_event(BankAccount& account, Portfolio& portfolio, Investment& investment) {
	std::cout << message;
	int option;

	std::cout << "1. Sell Investment\n";
	std::cout << "2. Buy Investment\n";

	std::cin >> option;

	switch(option) {
		case 1:
			portfolio.sellInvestment(0, account);
			break;
		case 2:
			portfolio.buyInvestment(&investment, account);
			break;
		default:
			std::cout << "Invalid option. No action taken.\n";
			break;
	}



}
