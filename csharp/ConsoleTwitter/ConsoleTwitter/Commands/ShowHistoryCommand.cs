using ConsoleTwitter.Posts;

namespace ConsoleTwitter.Commands;

public class ShowHistoryCommand : ICommand
{
    private readonly Posts.PostsCollection _postsCollection;
    private readonly Posts.CommandParts _commandParts;

    internal ShowHistoryCommand(Posts.PostsCollection posts, Posts.CommandParts command)
    {
        _postsCollection = posts ?? throw new ArgumentNullException(nameof(posts));
        _commandParts = command ?? throw new ArgumentNullException(nameof(command));
    }

    public string Execute()
    {
        return "";
    }
}
