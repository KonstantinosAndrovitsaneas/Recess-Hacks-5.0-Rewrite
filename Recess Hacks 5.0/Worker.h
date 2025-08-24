#pragma once
#include <vector>
#include "Portfolio.h"

class Worker {
public:
	int current_mood;
	int salery;

	int productive;
	int anxious;
	int greedy;

	int id;

	Worker(int id);

	void Update();

private:
	void CreateProfit(int percentage_chance);
	void AskForRaise(int percentage_chance);
	void CheckWorkspace(int percentage_chance);
	void PromptRaise(int id, int amount);
};

void HireWorker();

void FireWorker(int id);

void CalculateWorkerSaleries();

void PrintWorkerDataList();

extern std::vector<Worker> workers;

extern BankAccount profit_account;

extern Portfolio portfolio;