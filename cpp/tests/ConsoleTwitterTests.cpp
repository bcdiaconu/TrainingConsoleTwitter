#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ConsoleTwitter.h"

TEST_CASE("Empty wall before post")
{
	auto wallContents = sendInput("Alice");

	CHECK_EQ(0, wallContents.size());
}
