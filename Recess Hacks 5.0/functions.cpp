#include "functions.h"
#include "Worker.h"
#include <iostream>
#include <random>
void clearScreenANSI() {

    std::cout << "\033[2J\033[1;1H";

}

void menu_function(BankAccount& account, Portfolio& portfolio);

void manage_workers(Portfolio& portfolio, BankAccount& account) {
    int user_input;




    std::cout << "1. Hire Worker\n";
    std::cout << "2. Fire Worker\n";
    std::cout << "3. List Workers\n";
    std::cout << "4. Back to Main Menu\n";
    std::cin >> user_input;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number.\n";
    }

    switch (user_input) {
    case 1:
        HireWorker();
        std::cout << "Hired Worker!!\n";
        std::cout << "You may only hire one worker per day\n";
        next_day(portfolio, account);
        break;
    case 2:
        std::cout << "Enter the ID of the worker to fire: ";
        std::cin >> user_input;
       
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
        }
        
        FireWorker(user_input);
        break;
    case 3:
        std::cout << "\n";
        Worker::printWorkers();   
        std::cout << "\n";
        break;
    case 4:
        menu_function(account, portfolio);
        break;
    }
}

void manage_investments(Portfolio& portfolio, BankAccount& account) {
    int user_input;
    std::string name;

    std::cout << "1. Buy Investment\n";
    std::cout << "2. Sell Investment\n";
    std::cout << "3. List Investments\n";
    std::cout << "4. View Your Investments\n";
    std::cout << "5. Back to Main Menu\n";
    std::cin >> user_input;
    
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number.\n";
    }


    std::cout << "\n";

    switch (user_input) {
    case 1: {
        std::cout << "Enter the name of the investment exactly as it appears: ";
        Investment::list_available();

        std::cin.ignore();
        std::getline(std::cin, name);

        Investment* inv = Investment::getInvestmentByName(name);
        if (inv != nullptr) {
            portfolio.buyInvestment(inv, account);
            std::cout << "You may only buy one investment per day\n";
            next_day(portfolio, account);
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

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number.\n";
    }
    
    std::cout << "\n";
    switch (user_input) {
    case 1:
        std::cout << "Balance: " << account.get_balance() << "\n";
        break;
    case 2:
        manage_investments(portfolio, account);
        break;
    case 3:
        manage_workers(portfolio, account);
        break;
    case 4:
        next_day(portfolio, account);
        break;
    }
}

int week_day = 0;
int total_day = 0;
int blah = 0;
void next_day(Portfolio& portfolio, BankAccount& account) {
    total_day++;

    // update investments
    for (auto* inv : portfolio.investments) {
        inv->update_value();
    }
    for (auto* inv : Investment::all_investments) {
        inv->update_value();
    }

    week_day++;
    if (week_day == 7) {
        double salary = CalculateWorkerSaleries(account);   
        if (salary > 0) {
            std::cout << "Withdrew $" << salary << " for worker salaries\n";
        }
        else {
            std::cout << "You have no workers to pay\n";
            std::cout << "Maybe you want to hire some?\n";
        }
        week_day = 0;
    }

    for (int i = 0; i < workers.size(); i++) {
        workers[i].Update(account);   
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);

    if (dist(gen) < 3) {
        if (!Events::simple_events.empty()) {
            std::uniform_int_distribution<> eventDist(0, Events::simple_events.size() - 1);
            int idx = eventDist(gen);
            Events::simple_events[idx]->simple_event(account, portfolio);
        }
    
    }
    std::cout << total_day << " Days Have Passed\n";
    std::cout << "Press 1 to continue\n";
    std::cin >> blah;

    clearScreenANSI();

}
