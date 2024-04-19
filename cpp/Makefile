run: compile
	out/consoleTwitter

compile: out
	g++ -std=c++20 -Isrc/ src/ConsoleTwitter.cpp src/Main.cpp -oout/consoleTwitter

runTests: compileTests
	out/consoleTwitterTests

compileTests: out
	g++ -std=c++20 -Isrc/ -Itests/ src/ConsoleTwitter.cpp tests/ConsoleTwitterTests.cpp -oout/consoleTwitterTests

out:
	mkdir -p out/

clean:
	rm -rf out/
