#pragma once
#ifndef CONSOLETWITTER_H
#define CONSOLETWITTER_H

#include <list>
#include <string>
#include <sstream>
#include <algorithm>


std::string sendInput(const std::string& command);

std::list<std::string> parseCommand(const std::string& command);

std::string formatOutput(const std::string& userName, const std::string& header);
#endif
