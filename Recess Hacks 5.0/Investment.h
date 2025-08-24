#pragma once
#include <vector>
class Investment {


	public:
	double capital;
	double growth_rate;

	Investment(double initial_capital, double rate);

	double update_value();
	double get_value() const;

};