Console.WriteLine("Welcome to Console Twitter");

var consoleTwitter = new ConsoleTwitter.ConsoleTwitter();

while (true)
{
    Console.WriteLine(
        "Commands: <userName> for timeline, <userName> wall for wall, <userName> -> message to post, <userName> follows <userName> for follow"
    );
    Console.WriteLine("Type your command:");
    string? command = Console.ReadLine();
    string output = consoleTwitter.sendInput(command ?? "");
    Console.WriteLine();
    Console.WriteLine(output);
}
