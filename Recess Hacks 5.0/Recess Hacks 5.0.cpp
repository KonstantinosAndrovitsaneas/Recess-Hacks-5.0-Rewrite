// Recess Hacks 5.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "BankAccount.h"
#include "Investment.h"
#include "Portfolio.h"

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
		portfolio.buyInvestment(, account);
		break;
	case 2:
		portfolio.




}

void menu_function(BankAccount& account, Portfolio& portfolio) {
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
		portfolio.listInvestments();
		











}




int main()
{
	bool game_running = true;

	while (game_running) {
	
	
	
	}
}