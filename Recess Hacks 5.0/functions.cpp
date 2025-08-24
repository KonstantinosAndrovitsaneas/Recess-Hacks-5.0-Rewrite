#include "functions.h"
#include <iostream>

void menu_function(BankAccount& account, Portfolio& portfolio); // forward declaration

void manage_investments(Portfolio& portfolio, BankAccount& account) {
    int user_input;
    std::string name;

    std::cout << "1. Buy Investment\n";
    std::cout << "2. Sell Investment\n";
    std::cout << "3. List Investments\n";
    std::cout << "4. View Your Investments\n";
    std::cout << "5. Back to Main Menu\n";
    std::cin >> user_input;

    switch (user_input) {
    case 1:
        std::cout << "Enter the name of the investment exactly as it appears: ";
        std::cin.ignore(); 
        std::getline(std::cin, name);
        portfolio.buyInvestment(Investment::getInvestmentByName(name), account);
        std::cout << "You may only buy one investment per day\n";
        next_day(portfolio);

        break;
    case 2:
        std::cout << "Enter the index of the investment (starting from 1): \n";
        portfolio.listInvestments();
        std::cin >> user_input;
        portfolio.sellInvestment(user_input - 1, account);
        std::cout << "\n";

        break;
    case 3:
        Investment::list_available();
        break;
    case 4:
        portfolio.listInvestments();
        break;
    case 5:
        menu_function(account, portfolio);
        break;
    }
}

void menu_function(BankAccount& account, Portfolio& portfolio) {
    int user_input;
    std::cout << "\n";
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
        manage_investments(portfolio, account);
        break;
    case 3:
        // worker functionality
        break;
    case 4:
        next_day(portfolio);
        break;
    }
}

void next_day(Portfolio& portfolio) {
        for (auto* inv : portfolio.investments) {
            inv->update_value();
        }
    }
