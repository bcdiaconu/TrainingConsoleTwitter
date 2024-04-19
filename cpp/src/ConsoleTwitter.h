#pragma once
#ifndef CONSOLETWITTER_H
#define CONSOLETWITTER_H

#include <list>
#include <string>
#include <sstream>
#include <algorithm>

using UserName = std::string;
using Message = std::string;

class Post{
	public:
		const UserName userName;
		const Message message;
		Post(const UserName userName, const Message message) : userName(userName), message(message){};
};

using Posts = std::list<Post>;
using string = std::string;
using CommandParts = std::list<std::string>;

class ConsoleTwitter{
	private:
		Posts posts;

	public:
		ConsoleTwitter() : posts(){};
		string sendInput(const string& command);

	private:
		CommandParts parseCommand(const string& command);
		string formatOutput(const UserName& userName, const string& header);
		string formatOutput(const UserName& userName, const string& header, const Posts& posts);
		Posts userPosts(const UserName& userName);
};
#endif
