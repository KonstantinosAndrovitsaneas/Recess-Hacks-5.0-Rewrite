#include <iostream>
#include <vector>
#include <string>
#include "Worker.h"
#include "BankAccount.h"
#include "functions.h"


#define _CRT_SECURE_NO_WARNINGS

std::string PrintPrompt() {
	std::string buffer;

	PrintWorkerDataList();

	std::cout << ">" << std::endl;
	std::cin >> buffer;

	return buffer;
}

std::vector<std::string> ParceCommand(std::string buffer) {
	char* token = strtok((char*)buffer.c_str(), " ");

	std::vector<std::string> tokens;

	while (token != NULL) {
		tokens.push_back(token);
		token = strtok(NULL, " ");
	}

	return tokens;
}

void Manage(std::vector<std::string> parameters) {
	if (parameters[1] == "hire") {
		//if (Prompt("Hiring would cost you $100"))
		if (profit_account.withdraw(100))
			HireWorker();
	}
	else if (parameters[1] == "fire")
		FireWorker(stoi(parameters[2]));
}

void Help() {
	std::cout << "\n";
	std::cout << "bank - View bank account\n";
	std::cout << "manage -  Manage workers with the hire and fire {id} parameters\n";
	std::cout << "invest - manage investments\n";
	std::cout << "skip - Complete the day\n";
}

void ExecCommand(std::vector<std::string> parsed_command) {

	std::string command = parsed_command[0].c_str();


	/*if (command == "exit")
		exit(0);
	else if (command == "manage")
		Manage(parsed_command);
	else if (command == "bank")
		std::cout << profit_account.get_balance() << std::endl;
	else if (command == "skip")
		next_day(portfolio);
	else if (command == "help")
		Help();
	else if (command == "invest")
		manage_investments(portfolio, profit_account);
	else
		std::cout << "COMMAND NOT FOUND" << std::endl;*/
}

void RunShellRound() {
	std::string command = PrintPrompt();
	ExecCommand(ParceCommand(command));
}

bool Prompt(std::string comment) {
	std::string buffer;

	while (1) {
		std::cout << comment << " (y or n)" << std::endl;
		std::cin >> buffer;

		if (buffer == "y")
			return true;
		else if (buffer == "n")
			return false;
	}
}
