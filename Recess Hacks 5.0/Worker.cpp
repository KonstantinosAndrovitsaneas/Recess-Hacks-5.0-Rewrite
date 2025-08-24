#include <vector>
#include "Shell.h"
#include "BankAccount.h"
#include "Worker.h"
//#include "Portfolio.h"
#include <iostream>

std::vector<Worker> workers;

Portfolio portfolio;
BankAccount profit_account(1000);

Worker::Worker(int id) {
	salery = rand() % 100;
	productive = rand() % 100;
	greedy = rand() % 100;
	anxious = rand() % 100;
	id = id;
}

inline bool PercentageChance(int percent) {
	if (rand() % 100 <= percent)
		return true;
	return false;
}

void Worker::CreateProfit(int percentage_chance) {
	if (!PercentageChance(percentage_chance))
		return;
	profit_account.deposit(rand() % 100);
}

void Worker::PromptRaise(int id, int amount) {
	if (Prompt("WORKER #" + std::to_string(id) + " REQUESTS A RAISE OF: " + std::to_string(amount))) {
		workers[id].salery += amount;
		workers[id].current_mood++;
	}
	else
		workers[id].current_mood--;
}

void Worker::AskForRaise(int percentage_chance) {
	if (!PercentageChance(percentage_chance))
		return;
}

int space = 20;

void Worker::CheckWorkspace(int percentage_chance) {
	if (!PercentageChance(percentage_chance))
		return;
	if (space / 2 <= workers.size())
		current_mood--;
	else
		current_mood++;
}

void Worker::Update() {
	CreateProfit((productive + anxious + current_mood) / 3);
	AskForRaise(greedy);
	CheckWorkspace((anxious + current_mood) / 2);

	if (current_mood == 0) {
		FireWorker(id);
	}
}

static int worker_id = 0;

void HireWorker() {
	Worker worker(worker_id);
	worker_id++;

	workers.push_back(worker);
}

void FireWorker(int id) {
	for (int i = 0; i < workers.size(); i++) {
		if(workers[i].id == id)
			workers.erase(workers.begin() + i);
	}
}

void CalculateWorkerSaleries() {
	for (Worker worker : workers) {
		profit_account.withdraw(worker.salery);
	}
}

int FindWorker(int id) {
	for (int i = 0; i < workers.size(); i++)
		if (workers[i].id == id)
			return id;
	return NULL;
}

void PrintWorkerData(int id) {
	int loc = FindWorker(id);
	if (loc == NULL)
		return;

	std::cout << "WORKER #" << id << "\n";
	std::cout << "	Salery: " << workers[loc].salery << " Mood: " << workers[loc].current_mood << std::endl;
}

void PrintWorkerDataList() {
	for (Worker worker : workers) {
		std::cout << "WORKER #" << std::to_string(worker.id) << "\n";
		std::cout << "	Salery: " << std::to_string(worker.salery) << " Mood: " << std::to_string(worker.current_mood) << std::endl;
	}
}