#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ConsoleTwitter.h"

TEST_CASE("Empty timeline for Alice before post"){
	ConsoleTwitter consoleTwitter;
	std::string output = consoleTwitter.sendInput("Alice");

	CHECK_EQ("Alice Timeline\nNo posts found\n", output);
}

TEST_CASE("Empty wall for Alice before post"){
	ConsoleTwitter consoleTwitter;
	std::string output = consoleTwitter.sendInput("Alice wall");

	CHECK_EQ("Alice Wall\nNo posts found\n", output);
}

TEST_CASE("One post on Alice's timeline after posting"){
	ConsoleTwitter consoleTwitter;
	std::string output = consoleTwitter.sendInput("Alice -> A message");

	CHECK_EQ("Alice posted message 'A message'\n", output);

	output = consoleTwitter.sendInput("Alice");

	CHECK_EQ("Alice Timeline\nA message\n", output);
}

TEST_CASE("Bob's timeline is empty after Alice posts") {
	ConsoleTwitter consoleTwitter;
	std::string output = consoleTwitter.sendInput("Alice -> A message");

	output = consoleTwitter.sendInput("Bob");

	CHECK_EQ("Bob Timeline\nNo posts found\n", output);
}
