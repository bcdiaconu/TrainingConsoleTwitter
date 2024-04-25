using ConsoleTwitter.Posts;

namespace ConsoleTwitter.Commands;

public class ShowUserWall : ICommand
{
    private readonly Posts.PostsCollection _postsCollection;
    private readonly Posts.CommandParts _commandParts;

    internal ShowUserWall(Posts.PostsCollection posts, Posts.CommandParts command)
    {
        _postsCollection = posts ?? throw new ArgumentNullException(nameof(posts));
        _commandParts = command ?? throw new ArgumentNullException(nameof(command));
    }

    public string Execute()
    {
        var userName = _commandParts.First();
        var userCommand = _commandParts.Last();
        if (userCommand != "wall")
            return "Bad command '" + command + "'";
        return OutputFormatter.FormatOutput(userName, "Wall", userAndFollowedPosts(userName), true);
    }
}
