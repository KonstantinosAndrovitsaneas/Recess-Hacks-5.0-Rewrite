#pragma once
#include "Investment.h"
#include "Portfolio.h"
#include "BankAccount.h"
class Events {
public:
	double amount;
	std::string message;
	
	static std::vector<Events*> simple_events;


	static void simple_event(BankAccount& account, Portfolio& portfolio);
	static void complex_event(BankAccount& account, Portfolio& portfolio, Investment& investment);


};