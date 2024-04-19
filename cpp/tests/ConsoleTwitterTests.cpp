#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ConsoleTwitter.h"

TEST_CASE("No post for Alice before post"){
	auto posts = sendInput("Alice");

	CHECK_EQ(0, posts.size());
}

TEST_CASE("Empty wall for Alice before post"){
	auto wallContents = sendInput("Alice wall");

	CHECK_EQ(0, wallContents.size());
}
