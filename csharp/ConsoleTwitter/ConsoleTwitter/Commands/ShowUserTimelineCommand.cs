using ConsoleTwitter.Posts;

namespace ConsoleTwitter.Commands;

public class ShowUserTimelineCommand : ICommand
{
    private readonly Posts.PostsCollection _postsCollection;
    private readonly Posts.CommandParts _commandParts;

    internal ShowUserTimelineCommand(Posts.PostsCollection posts, Posts.CommandParts command)
    {
        _postsCollection = posts ?? throw new ArgumentNullException(nameof(posts));
        _commandParts = command ?? throw new ArgumentNullException(nameof(command));
    }

    public string Execute()
    {
            var userName = _commandParts.First();

            return OutputFormatter.FormatOutput(userName, "Timeline", _postsCollection.FilterUserPosts(userName), false);
    }
}
