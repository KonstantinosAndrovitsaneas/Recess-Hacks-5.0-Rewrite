#include <vector>
#include "Shell.h"

class Worker {
public:
	int current_mood;
	int salery;
	
	int productive;
	int anxious;
	int greedy;
	
	Worker();

	void Update();

	void Leave();

private:
	void CreateProfit(int percentage_chance);
	void AskForRaise(int percentage_chance);
	void CheckWorkspace(int percentage_chance);
	void PromptRaise(int id, int amount);
};

std::vector<Worker> workers;

Worker::Worker() {
	productive = rand() % 100;
	salery = rand() % 100;
	greedy = rand() % 100;
	anxious = rand() % 100;
}

inline bool PercentageChance(int percent) {
	if (rand() % 100 <= percent)
		return true;
	return false;
}

void Worker::CreateProfit(int percentage_chance) {
	if(PercentageChance(percentage_chance))
	{
		//YAY PROFIT
	}
}

void Worker::PromptRaise(int id, int amount) {
	/*if (Prompt("WORKER #" + id + " REQUESTS A RAISE OF: " + amount)) {
		workers[id].salery += amount;
		workers[id].current_mood++;
	}
	else
		workers[id].current_mood--;*/
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
	CheckWorkspace();

	if (current_mood == 0) {
		//this.Leave()
	}
}

void HireWorker() {
	Worker worker();

	workers.push_back(worker);
	
}

void FireWorker(int id) {
	workers.erase(workers.begin() + id);
}