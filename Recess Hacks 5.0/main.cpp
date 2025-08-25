// Recess Hacks 5.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "BankAccount.h"
#include "Investment.h"
#include "Portfolio.h"
#include "functions.h"
#include "Worker.h"
#include "Events.h"





int main()
{
	bool game_running = true;

	BankAccount profit_account(10000000.00);
	Portfolio portfolio;

		

	Investment inv1(500.0, 10.0, "Tech Startup");
	Investment inv2(300.0, 3.0, "Real Estate");
	Investment inv3(200.0, 2.0, "Bonds");	
	Investment inv4(100.0, 1.0, "Savings Account");	
	Investment inv5(1000, 60.0, "Cryptocurrency");
	Investment inv6(250.0, 2.5, "Index Fund");
	Investment inv7(150.0, 4.0, "Commodities");
	Investment inv8(350.0, 7.0, "Mutual Fund");	
	Investment inv9(450.0, 20.0, "Venture Capital");
	Investment inv10(600.0, 30.0, "Hedge Fund");


	Events event1(100.0, "A worker got sick and you had to pay for their medical bills. You lost $100.\n");	
	Events event2(-200.0, "You received a tax refund! You gained $200.\n");
	Events event3(50.0, "Your office was robbed! You lost $50.\n");
	Events event4(-150.0, "You won a small business grant! You gained $150.\n");
	Events event5(75.0, "You had to pay a fine for a minor regulatory violation. You lost $75.\n");
	Events event6(-300.0, "A major client paid their invoice early! You gained $300.\n");
	Events event7(200.0, "You had to replace some stolen equipment. You lost $200.\n");
	Events event8(-250.0, "You received a bonus from a satisfied customer! You gained $250.\n");
	Events event9(150.0, "You had to pay for unexpected repairs. You lost $150.\n");
	Events event10(-100.0, "You sold some old equipment and made a profit! You gained $100.\n");



	std::cout << "HELLO! You will be acting as a business owner in this game. Your goal is to make investments, manage workers, and maximize profits for your company\n";
	std::cout << "You will start with $500 in your bank account. You can buy investments to grow your money, and hire workers to help manage your business.\n";
	std::cout << "Workers will produce money for you, but they will have a fixed salary that you must pay at the end of every week\n";
	std::cout << "Investments grow and shrink in value over time, so be careful when buying them!\n";
	std::cout << "You'll also need to manage worker mood, as unhappy workers may leave or perform poorly\n";
	std::cout << "But if a worker is happy, they may produce more money for you!\n";
	std::cout << "Workers will be unhappy if they have to work with lots of other people in a small space, or if you constantly decline their raise requests\n";
	std::cout << "And sometimes, random events may occur that can impact your business positively or negatively\n";
	std::cout << "You lose if you go bankrupt!\n";
	std::cout << "There isn't a way to win, but try to make as much money as you can!\n";
	std::cout << "Good luck, and have fun!\n";
	std::cout << "\n";

	while (game_running) {
	
		menu_function(profit_account, portfolio);
		if (profit_account.get_balance() <= 0) {
			game_running = false;
		}
	}
}

