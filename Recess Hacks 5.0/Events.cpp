#include "Events.h"
#include <iostream>

std::vector<Events*> Events::simple_events;

Events::Events(double amount, std::string message) : amount(amount), message(message) {
    simple_events.push_back(this);
}

void Events::simple_event(BankAccount& account, Portfolio& portfolio) {
    std::cout << message;
    if (amount > account.balance) {
        amount = account.balance;
    }
    account.withdraw(amount);
}
