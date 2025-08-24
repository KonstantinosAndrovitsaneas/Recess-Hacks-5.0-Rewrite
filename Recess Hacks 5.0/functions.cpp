#include "functions.h"
#include "Worker.h"
#include <iostream>
#include <random>

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
    case 1: {
        std::cout << "Enter the name of the investment exactly as it appears: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        Investment* inv = Investment::getInvestmentByName(name); 
        if (inv != nullptr) {
            portfolio.buyInvestment(inv, account);
            std::cout << "You may only buy one investment per day\n";
            next_day(portfolio,account);
        }
        else {
            std::cout << "Invalid name for investment\n";
        }
        break;
    }

    case 2:
        std::cout << "Enter the index of the investment (starting from 1): \n";
        portfolio.listInvestments();
        std::cin >> user_input;

        if (std::cin.fail()) {
            std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";        
        }

        else {
            portfolio.sellInvestment(user_input - 1, account);
            std::cout << "\n";
        }
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
        
        break;
    case 4:
        next_day(portfolio,account);
        break;
    }
}

int week_day = 1;

void next_day(Portfolio& portfolio, BankAccount& account) {
    for (auto* inv : portfolio.investments) {
        inv->update_value();
    }

    week_day++;
    if (week_day == 7) {
        CalculateWorkerSaleries();
        week_day = 0;
    }

    for (int i = 0; i < workers.size(); i++) {
        workers[i].Update();
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(1, 10);

    if (dist(gen) == 4 or dist(gen) == 9) {
    
    
    }



}


