#include "functions.h"
#include <iostream>

void manage_investments(Portfolio& portfolio, BankAccount& account) {

	int user_input;
	std::string name;

	std::cout << "1. Buy Investment\n";
	std::cout << "2. Sell Investment\n";
	std::cout << "3. List Investments\n";
	std::cout << "4. Back to Main Menu\n";
	std::cin >> user_input;

	switch (user_input) {
	case 1:
		std::cout << "What investment do you want to buy?\n";
		std::cout << "Enter the name of the investment exactly as it appears: ";
		std::cin >> name;

		portfolio.buyInvestment(Investment::getInvestmentByName(name), account);
		break;
	case 2:
		std::cout << "What investment do you want to sell?\n";
		std::cout << "Enter the index of the investment (starting from 1): ";
		portfolio.listInvestments();
		std::cin >> user_input;
		portfolio.sellInvestment(user_input - 1, account);
		break;
	case 3:
		portfolio.listInvestments();
		break;
	case 4:
		menu_function(account, portfolio);




	}


	void menu_function(BankAccount & account, Portfolio & portfolio) {
		int user_input;

		std::cout << "1. View Bank Account\n";
		std::cout << "2. Manage Investments\n";
		std::cout << "3. Manage Workers\n";
		std::cout << "4. Next Day\n";

		std::cin >> user_input;



		switch (user_input) {
		case 1:
			std::cout << "Balance: " << account.get_balance() << "\n";
			break;
		case 2:
			std::cout << "Investments:\n";
			manage_investments(portfolio, account);
			break;
		case 3:
			//worker functionality
		case 4:
			//Next day functionality

		}
