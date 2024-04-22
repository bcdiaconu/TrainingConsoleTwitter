using ConsoleTwitter;
using Xunit;
namespace ConsoleTwitter.Tests;

public class ConsoleTwitterTest
{
    [Fact]
    void Empty_timeline_for_Alice_before_post()
    {
        ConsoleTwitter consoleTwitter = new ConsoleTwitter();
        string output = consoleTwitter.sendInput("Alice");

        Assert.Equal("Alice Timeline\nNo posts found\n", output);
    }

    [Fact]
    public void Empty_wall_for_Alice_before_post()
    {
        ConsoleTwitter consoleTwitter = new ConsoleTwitter();
        string output = consoleTwitter.sendInput("Alice wall");

        Assert.Equal("Alice Wall\nNo posts found\n", output);
    }

    [Fact(Skip = "")]
    public void Confirmation_shown_after_posting_message()
    {
        ConsoleTwitter consoleTwitter = new ConsoleTwitter();

        string output = consoleTwitter.sendInput("Alice -> A message");

        Assert.Equal("Alice posted message 'A message'\n", output);
    }

    [Fact(Skip = "")]
    public void One_post_on_Alices_timeline_after_posting()
    {
        ConsoleTwitter consoleTwitter = new ConsoleTwitter();
        consoleTwitter.sendInput("Alice -> A message");

        string output = consoleTwitter.sendInput("Alice");

        Assert.Equal("Alice Timeline\nA message\n", output);
    }

    [Fact(Skip = "")]
    public void Bobs_timeline_is_empty_after_Alice_posts()
    {
        ConsoleTwitter consoleTwitter = new ConsoleTwitter();
        consoleTwitter.sendInput("Alice -> A message");

        string output = consoleTwitter.sendInput("Bob");

        Assert.Equal("Bob Timeline\nNo posts found\n", output);
    }

    [Fact(Skip = "")]
    public void Bobs_timeline_shows_only_Bobs_post_after_both_Alice_and_Bob_post()
    {
        ConsoleTwitter consoleTwitter = new ConsoleTwitter();
        consoleTwitter.sendInput("Alice -> Alice's message");
        consoleTwitter.sendInput("Bob -> Bob's message");

        string output = consoleTwitter.sendInput("Bob");

        Assert.Equal("Bob Timeline\nBob's message\n", output);
    }

    [Fact(Skip = "")]
    public void Confirmation_shown_on_follow()
    {
        ConsoleTwitter consoleTwitter = new ConsoleTwitter();

        string output = consoleTwitter.sendInput("Bob follows Alice");

        Assert.Equal("Bob is now following Alice\n", output);
    }

    [Fact(Skip = "")]
    public void Bobs_wall_shows_both_Alice_and_Bob_posts_after_Bob_follows_Alice()
    {
        ConsoleTwitter consoleTwitter = new ConsoleTwitter();
        consoleTwitter.sendInput("Alice -> Alice's message");
        consoleTwitter.sendInput("Bob -> Bob's message");
        consoleTwitter.sendInput("Bob follows Alice");

        string output = consoleTwitter.sendInput("Bob wall");

        Assert.Equal("Bob Wall\nAlice - Alice's message\nBob - Bob's message\n", output);
    }

    [Fact(Skip = "")]
    public void Bobs_timeline_shows_only_Bob_posts_after_Bob_follows_Alice()
    {
        ConsoleTwitter consoleTwitter = new ConsoleTwitter();
        consoleTwitter.sendInput("Alice -> Alice's message");
        consoleTwitter.sendInput("Bob -> Bob's message");
        consoleTwitter.sendInput("Bob follows Alice");

        string output = consoleTwitter.sendInput("Bob");

        Assert.Equal("Bob Timeline\nBob's message\n", output);
    }
}
