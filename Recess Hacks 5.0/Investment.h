#pragma once
#include <vector>
#include <iostream>
#include <string>
class Investment {


	public:
	double capital;
	double growth_rate;
	std::string name;
	
	static std::vector<Investment*> all_investments;

	Investment(double initial_capital, double rate, std::string new_name);

	double update_value();
	double get_value() const;
	static Investment* getInvestmentByName(const std::string& name);

};