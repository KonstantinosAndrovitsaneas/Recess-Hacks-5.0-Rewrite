#pragma once
#include "Investment.h"
#include "Portfolio.h"
#include "BankAccount.h"
#include <vector>
#include <string>

class Events {
public:
    double amount;
    std::string message;

    static std::vector<Events*> simple_events;

    Events(double amount, std::string message);

    void simple_event(BankAccount& account, Portfolio& portfolio);
};
