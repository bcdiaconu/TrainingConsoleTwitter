#pragma once
#ifndef CONSOLETWITTER_H
#define CONSOLETWITTER_H

#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

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
using Users = std::list<UserName>;

class ConsoleTwitter{
	private:
		Posts posts;
		std::map<UserName, Users> followed;
	public:
		ConsoleTwitter() : posts(){};
		string sendInput(const string& command);

	private:
		CommandParts parseCommand(const string& command);
		string formatOutput(const UserName& userName, const string& header);
		string formatOutput(const UserName& userName, const string& header, const Posts& posts, bool withUser);
		Posts userPosts(const UserName& userName);
		Posts userAndFollowedPosts(const UserName& userName);
		bool contains(const Users users, UserName userName){
			return std::find(users.begin(), users.end(), userName) != users.end();
		};
};
#endif
