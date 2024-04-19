#include "ConsoleTwitter.h"
#include <functional>

std::list<std::string> posts;

std::string sendInput(const std::string& command){
	auto commandWords = parseCommand(command);

	if(commandWords.size() == 1){
		std::string userName = commandWords.front();
		return formatOutput(userName, "Timeline");
	}

	if(commandWords.size() == 2){
		std::string userName = commandWords.front();
		std::string userCommand = commandWords.back();
		return formatOutput(userName, userCommand);
	}

	if(commandWords.size() >= 3){
		std::string userName = commandWords.front();
		commandWords.pop_front();

		std::string command = commandWords.front();
		if(command != "->") return "Command error";
		commandWords.pop_front();

		std::string message;
		for(auto commandWord = commandWords.begin(); commandWord != commandWords.end(); commandWord++){
			if(commandWord == commandWords.begin()){
				message += *commandWord;
			} else {
				message += " " + *commandWord;
			}
		}

		posts.push_back(message);
		std::ostringstream outputFormatter;
		outputFormatter << userName << " posted message '" << message << "'" << std::endl;
		return outputFormatter.str();
	}
	return "";
}

std::list<std::string> parseCommand(const std::string& command){
	std::stringstream parser(command);
	std::string word;
	std::list<std::string> commandWords;
	while(parser>>word){
		commandWords.push_back(word);
	}
	return commandWords;
}

std::string formatOutput(const std::string& userName, const std::string& header){
	std::ostringstream outputFormatter;
	outputFormatter << userName << " " << header << std::endl;
	if(posts.size() == 0){
		outputFormatter << "No posts found" << std::endl;
	} else {
		for(auto post = posts.begin(); post != posts.end(); post++){
			outputFormatter << *post << std::endl;
		}
	}

	return outputFormatter.str();
}
