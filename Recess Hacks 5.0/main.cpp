// Recess Hacks 5.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "BankAccount.h"
#include "Investment.h"
#include "Portfolio.h"
#include "functions.h"
#include "Events.h"





int main()
{
	bool game_running = true;

	BankAccount account(1000.0); // Starting with $1000	
	Portfolio portfolio;	
	Investment inv1(500.0, 5.0, "Tech Startup");

	Events event1(100.0, "Market Crash! You lose $100 from your account.\n");

	while (game_running) {
	
		menu_function(account, portfolio);
	
	}
}