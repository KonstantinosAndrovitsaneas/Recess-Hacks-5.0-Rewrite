#include "Investment.h"
#include <iostream>
#include <random>
#include <vector>

std::vector<Investment*> Investment::all_investments;


Investment::Investment(double initial_capital, double rate, std::string new_name) : capital(initial_capital), growth_rate(rate), name(new_name) {

    all_investments.push_back(this);

}	


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

Investment* Investment::getInvestmentByName(const std::string& name) {
    for (auto* inv : all_investments) {
    if(inv-> name == name) {
		return inv;
    }
	}
    return nullptr;

}