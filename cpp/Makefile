runTests: compile
	out/consoleTwitter

compile: out
	g++ -std=c++20 -Isrc/ -Itests/ src/ConsoleTwitter.cpp tests/ConsoleTwitterTests.cpp -oout/consoleTwitter

out:
	mkdir -p out/

clean:
	rm -rf out/
