#include "ConsoleTwitter.h"
#include <iostream>

int main(){
	std::cout << "Welcome to Console Twitter" << std::endl;
	ConsoleTwitter consoleTwitter;

	while(true){
		std::cout << "Commands: <userName> for timeline, <userName> wall for wall, <userName> -> message to post, <userName> follows <userName> for follow" << std::endl;
		std::cout << "Type your command:";
		string command;
		std::getline(std::cin, command);
		string output = consoleTwitter.sendInput(command);
		std::cout << std::endl << output << std::endl;
	}
}
