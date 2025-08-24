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

	BankAccount account(300.0); // Starting with $1000	
	Portfolio portfolio;	
	
	Investment inv1(500.0, 5.0, "Tech Startup");
	Investment inv2(300.0, 3.0, "Real Estate");	
	Investment inv3(200.0, 2.0, "Bonds");
	Investment inv4(150.0, 4.0, "Cryptocurrency");	
	Investment inv5(400.0, 6.0, "Healthcare");	
	Investment inv6(250.0, 2.5, "Energy");	
	Investment inv7(350.0, 3.5, "Retail");
	Investment inv8(450.0, 4.5, "Automotive");
	Investment inv9(600.0, 5.5, "Pharmaceuticals");
	Investment inv10(700.0, 6.5, "Artificial Intelligence");




	Events event1(100.0, "Market Crash! You lose $100 from your account.\n");
	Events event2(-50.0, "Dividend Payout! You gain $50 in your account.\n");
	Events event3(-200.0, "Successful Investment! You gain $200 in your account.\n");
	Events event4(150.0, "Unexpected Expense! You lose $150 from your account.\n");
	Events event5(-75.0, "Market Rally! You gain $75 in your account.\n");
	Events event6(125.0, "Economic Downturn! You lose $125 from your account.\n");
	Events event7(-300.0, "Big Win! You gain $300 in your account.\n");
	Events event8(80.0, "Minor Setback! You lose $80 from your account.\n");
	Events event9(-60.0, "Steady Growth! You gain $60 in your account.\n");
	Events event10(-90.0, "Unexpected Opportunity! You gain $90 in your account.\n");
	Events event11(110.0, "Market Volatility! You lose $110 from your account.\n");
	Events event12(250, "Data Breach! You lose $250 from your account");
	



	while (game_running) {
	
		menu_function(account, portfolio);
		
		if(account.get_balance() <= 0.0) {
			std::cout << "You have run out of money! Game Over.\n";
			game_running = false;
		}
	}
}