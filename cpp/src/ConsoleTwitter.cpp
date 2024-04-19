#include "ConsoleTwitter.h"
#include <algorithm>

string ConsoleTwitter::sendInput(const string& command){
	auto commandWords = parseCommand(command);

	if(commandWords.size() == 1){
		auto userName = commandWords.front();
		return formatOutput(userName, "Timeline", userPosts(userName));
	}

	if(commandWords.size() == 2){ 
		auto userName = commandWords.front();
		auto userCommand = commandWords.back();
		if(userCommand != "wall") return "Bad command '" + command + "'";
		return formatOutput(userName, "Wall", userPosts(userName));
	}

	if(commandWords.size() >= 3){
		auto userName = commandWords.front();
		commandWords.pop_front();

		auto command = commandWords.front();
		if(command != "->") return "Bad command '" + command + "'";
		commandWords.pop_front();

		string message;
		for(auto commandWord = commandWords.begin(); commandWord != commandWords.end(); commandWord++){
			if(commandWord == commandWords.begin()){
				message += *commandWord;
			} else {
				message += " " + *commandWord;
			}
		}

		Post post(userName, message);
		posts.push_back(post);
		std::ostringstream outputFormatter;
		outputFormatter << userName << " posted message '" << message << "'" << std::endl;
		return outputFormatter.str();
	}
	return "";
}

CommandParts ConsoleTwitter::parseCommand(const std::string& command){
	std::stringstream parser(command);
	string part;
	CommandParts commandParts;
	while(parser>>part){
		commandParts.push_back(part);
	}
	return commandParts;
}


string ConsoleTwitter::formatOutput(const UserName& userName, const string& header){
	return formatOutput(userName, header, posts);
}

string ConsoleTwitter::formatOutput(const UserName& userName, const string& header, const Posts& posts){
	std::ostringstream outputFormatter;
	outputFormatter << userName << " " << header << std::endl;
	if(posts.size() == 0){
		outputFormatter << "No posts found" << std::endl;
	} else {
		for(auto post = posts.begin(); post != posts.end(); post++){
			outputFormatter << post->message << std::endl;
		}
	}

	return outputFormatter.str();
}

Posts ConsoleTwitter::userPosts(const UserName& userName){
	Posts userPosts;
	std::copy_if(std::begin(posts), std::end(posts), std::back_inserter(userPosts), [userName](Post& it){return it.userName == userName;});
	return userPosts;
}
