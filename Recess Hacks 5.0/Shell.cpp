#include <iostream>
#include <vector>
#include <string>

std::string PrintPrompt() {
	std::string buffer;

	std::cout << ">" << std::endl;
	std::cin >> buffer;

	return buffer;
}

std::vector<std::string> ParceCommand(std::string buffer) {
	
}

void ExecCommand(std::vector<std::string> parsed_command) {
	//switch (parsed_command[0].c_str) {
	///*case "buy":
	//case "sell":
	//case "invest":
	//case "bank":*/
	//default:
	//	std::cout << "COMMAND NOT FOUND" << std::endl;
	//};
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