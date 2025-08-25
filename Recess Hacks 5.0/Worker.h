#pragma once
#include <vector>
#include "Portfolio.h"

class Worker {
public:
    Worker(int id);

    static void printWorkers();
    void CreateProfit(int percentage_chance, BankAccount& account);
    void PromptRaise(int id, int amount, BankAccount& account);
    void AskForRaise(BankAccount& account);
    void CheckWorkspace(int percentage_chance);
    void Update(BankAccount& account);

    void PromptMoreSpace(int percentage_chance, BankAccount& account);

    int id;
    int salery;
    int productive;
    int greedy;
    int anxious;
    int current_mood;
};

void HireWorker();
void FireWorker(int id);
int FindWorker(int id);
double CalculateWorkerSaleries(BankAccount& account);
void PrintWorkerData(int id);
void PrintWorkerDataList();

extern std::vector<Worker> workers;

