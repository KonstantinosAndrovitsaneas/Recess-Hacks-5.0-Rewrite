// Recess Hacks 5.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "BankAccount.h"
#include "Investment.h"
#include "Portfolio.h"
#include "functions.h"
#include "Shell.h"
#include "Worker.h"





int main()
{
	bool game_running = true;


	// REPLACE WITH PROFIT ACCOUNT
	//BankAccount account(1000.0); // Starting with $1000	
		

	Investment inv1(500.0, 5.0, "Tech Startup");

	HireWorker();
	HireWorker();
	HireWorker();

	while (game_running) {
	
		menu_function(profit_account, portfolio);

		//RunShellRound();
	
	}
}