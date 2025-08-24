// Recess Hacks 5.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BankAccount.h"
#include "Investment.h"
#include "Portfolio.h"
int main()
{
	bool game_running = true;

	std::cout << "Placeholder message" << std::endl;

	BankAccount account(1000.0f);

	Investment nike(700, 5.0f);

	Portfolio my_portfolio;

	my_portfolio.buyInvestment(nike, account);

	my_portfolio.listInvestments();	
	
	my_portfolio.sellInvestment(0, account);

	my_portfolio.listInvestments();
}