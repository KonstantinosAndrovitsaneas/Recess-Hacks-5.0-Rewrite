#include <vector>
#include "Shell.h"
#include "BankAccount.h"
#include "Worker.h"
//#include "Portfolio.h"
#include <iostream>

void HireWorker();
void FireWorker(int id);
int FindWorker(int id);
double CalculateWorkerSaleries();
void PrintWorkerData(int id);
void PrintWorkerDataList();

std::vector<Worker> workers;


Worker::Worker(int id)
	: id(id),
	salery(200),
	productive(rand() % 100),
	greedy(rand() % 100),
	anxious(rand() % 100),
	current_mood(20)  
{
}


void Worker::printWorkers() {
	if (workers.size() > 0) {
		for (int i = 0; i < workers.size(); i++) {
			std::cout << "Worker #" << workers[i].id << " Salery: " << workers[i].salery << " Mood: " << workers[i].current_mood << std::endl;
		}
	}
	else {
	
		std::cout << "You have no workers!" << std::endl;
	}
}

inline bool PercentageChance(int percent) {
	if (rand() % 100 <= percent)
		return true;
	return false;
}

void Worker::CreateProfit(int percentage_chance, BankAccount& account) {
	if (!PercentageChance(percentage_chance))
		return;
	account.deposit(rand() % 100);
}
void Worker::PromptRaise(int id, int amount, BankAccount& account) {
	std::cout << "WORKER #" << id
		<< " REQUESTS A RAISE OF $" << amount
		<< ". Do you accept? (y/n): ";

	char choice;
	std::cin >> choice;

	if (choice == 'y' || choice == 'Y') {
		if (account.withdraw(amount,false)) {
			workers[id].salery += amount;
			workers[id].current_mood+=10;
			std::cout << "Raise granted!\n";
		}
		else {
			std::cout << "Not enough balance to grant the raise.\n";
		}
	}
	else {
		workers[id].current_mood-=10;
		std::cout << "Raise denied.\n";
	}
}

void Worker::AskForRaise(BankAccount& account) {
	if (!PercentageChance(8))
		return;

	int raiseAmount = static_cast<int>(salery * (greedy / 200.0));
	if (raiseAmount < 10) raiseAmount = 10;

	PromptRaise(id, raiseAmount, account);

}

int space = 20;

void Worker::CheckWorkspace(int percentage_chance) {
	if (!PercentageChance(percentage_chance))
		return;
	if (space / 2 <= workers.size())
		current_mood-=10;
	else
		current_mood+=10;
}

void Worker::PromptMoreSpace(int percentage_chance, BankAccount& account) {
	int total_mood = 0;
	for (const auto& w : workers) {
		total_mood += w.current_mood;
	}
	int average_mood = total_mood / workers.size();
	
	if (space / 2 <= workers.size() && average_mood <= 30) {
		if (!PercentageChance(percentage_chance)) {
			std::cout << "THE WORKERS ARE REQUESTING A SPACE INCREASE "
				<< "IT WILL COST $100 TO DO SO"
				<< ". Do you accept? (y/n): ";

			char choice;
			std::cin >> choice;

			if (choice == 'y' || choice == 'Y') {
				if (account.withdraw(100, false)) {
					space += 10;

					for (auto& w : workers) {
						w.current_mood += 10;
					}

					std::cout << "Space Increased\n";
				}
				else {
					std::cout << "Not enough balance to grant the space increase.\n";
				}
			}
			else {
				for (auto& w : workers) {
					w.current_mood -= 10;
				}

				std::cout << "Space increase denied. All workers are unhappy.\n";
			}
		}
	}
}


void Worker::Update(BankAccount& account) {
	CreateProfit((productive + anxious + current_mood) / 3, account);
	AskForRaise(account);
	CheckWorkspace((anxious + current_mood) / 2);
	PromptMoreSpace(15, account);
	if (current_mood < 30) {
		int quitChance = (30 - current_mood); 
		if (PercentageChance(quitChance)) {
			std::cout << "Worker #" << id << " has quit due to low mood.\n";
			FireWorker(id);
			return;
		}
	}

}

static int worker_id = 0;

void HireWorker() {
	Worker worker(worker_id);
	worker_id++;

	workers.push_back(worker);
}

void FireWorker(int id) {
	int index = FindWorker(id);
	if (index != -1) {
		workers.erase(workers.begin() + index);
		std::cout << "Worker #" << id << " was fired.\n";
	}
	else {
		std::cout << "Worker #" << id << " not found.\n";
	}
}


double CalculateWorkerSaleries(BankAccount& account) {
	if (workers.empty()) {
		return 0.0;
	}

	double total = 0.0;
	for (const Worker& worker : workers) {
		total += worker.salery;
	}

	account.withdraw(total, true);
	return total;
}


int FindWorker(int id) {
	for (int i = 0; i < workers.size(); i++) {
		if (workers[i].id == id)
			return i;
	}
	return -1;
}

void PrintWorkerData(int id) {
	int loc = FindWorker(id);
	if (loc == NULL)
		return;

	std::cout << "WORKER #" << id << "\n";
	std::cout << "	Salary: " << workers[loc].salery << " Mood: " << workers[loc].current_mood << std::endl;
}

void PrintWorkerDataList() {
	for (Worker const worker : workers) {
		std::cout << "WORKER #" << std::to_string(worker.id) << "\n";
		std::cout << "	Salary: " << std::to_string(worker.salery) << " Mood: " << std::to_string(worker.current_mood) << std::endl;
	}
}