#include "Investment.h"
#include <iostream>
#include <random>
Investment::Investment(double initial_capital, double rate) : capital(initial_capital), growth_rate(rate) {}	


double Investment::update_value() {
    double max = capital * (growth_rate / 100);
    double min = -max;

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(min, max);

    capital += dist(gen);
    return capital;
}


double Investment::get_value() const {
    return capital;
}   
