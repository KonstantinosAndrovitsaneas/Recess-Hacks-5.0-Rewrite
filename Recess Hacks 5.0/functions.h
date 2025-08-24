#pragma once

// Recess Hacks 5.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "BankAccount.h"
#include "Investment.h"
#include "Portfolio.h"
#include "Events.h"

void manage_investments(Portfolio& portfolio, BankAccount& account);
void menu_function(BankAccount& account, Portfolio& portfolio);	


void next_day(Portfolio& portfolio, BankAccount& account);