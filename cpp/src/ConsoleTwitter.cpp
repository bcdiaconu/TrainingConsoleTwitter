#include "ConsoleTwitter.h"
#include <algorithm>

string ConsoleTwitter::sendInput(const string& command){
	auto commandWords = parseCommand(command);

	if(commandWords.size() == 1){
		auto userName = commandWords.front();
		return formatOutput(userName, "Timeline", userPosts(userName), false);
	}

	if(commandWords.size() == 2){ 
		auto userName = commandWords.front();
		auto userCommand = commandWords.back();
		if(userCommand != "wall") return "Bad command '" + command + "'";
		return formatOutput(userName, "Wall", userAndFollowedPosts(userName), true);
	}

	if(commandWords.size() >= 3){
		auto userName = commandWords.front();
		commandWords.pop_front();

		auto command = commandWords.front();
		if(command != "->" && command != "follows") return "Bad command '" + command + "'";

		if(command == "->") {
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

		if(command == "follows"){
			commandWords.pop_front();
			string whoToFollow = commandWords.front();
			followed[userName].push_back(whoToFollow);
			std::ostringstream outputFormatter;
			outputFormatter << userName << " is now following " << whoToFollow << std::endl;
			return outputFormatter.str();
		}
	}
	return "Bad command '" + command + "'";
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
	return formatOutput(userName, header, posts, false);
}

string ConsoleTwitter::formatOutput(const UserName& userName, const string& header, const Posts& posts, bool withUser){
	std::ostringstream outputFormatter;
	outputFormatter << userName << " " << header << std::endl;
	if(posts.size() == 0){
		outputFormatter << "No posts found" << std::endl;
	} else {
		for(auto post = posts.begin(); post != posts.end(); post++){
			if(withUser){
				outputFormatter << post->userName << " - " << post->message << std::endl;
			} else {
				outputFormatter << post->message << std::endl;
			}
		}
	}

	return outputFormatter.str();
}

Posts ConsoleTwitter::userPosts(const UserName& userName){
	Posts userPosts;
	std::copy_if(std::begin(posts), std::end(posts), std::back_inserter(userPosts), [userName](Post& it){return it.userName == userName;});
	return userPosts;
}

Posts ConsoleTwitter::userAndFollowedPosts(const UserName& userName){
	Posts userPosts;
	std::copy_if(std::begin(posts), std::end(posts), std::back_inserter(userPosts), [userName, this](Post& it){return it.userName == userName || contains(followed[userName], it.userName) ;});
	return userPosts;
}
