namespace ConsoleTwitter.Commands;

public class ShowUserFollowsCommand : ICommand
{
    private readonly Posts.PostsCollection _postsCollection;
    private readonly Posts.CommandParts _commandParts;

    internal ShowUserFollowsCommand(Posts.PostsCollection posts, Posts.CommandParts command)
    {
        _postsCollection = posts ?? throw new ArgumentNullException(nameof(posts));
        _commandParts = command ?? throw new ArgumentNullException(nameof(command));
    }

    public string Execute()
    {
        Dictionary<string, Posts.Users> followed = new Dictionary<string, Posts.Users>();
        var userName = _commandParts.First();
            _commandParts.RemoveAt(0);

            var theCommand = _commandParts.First();
            if (theCommand != "->" && theCommand != "follows")
                return "Bad command '" + _commandParts + "'";

            if (theCommand == "->")
            {
                _commandParts.RemoveAt(0);
                string message = String.Join(" ", _commandParts);
                var post = new Posts.Post(userName, message);
                _postsCollection.Add(post);
                return $"{userName} posted message '{message}'\n";
            }

            if (theCommand == "follows")
            {
                _commandParts.RemoveAt(0);
                string whoToFollow = _commandParts.First();
                if (!followed.ContainsKey(userName))
                {
                    followed.Add(userName, new Posts.Users());
                }
                followed[userName].Add(whoToFollow);
                return $"{userName} is now following {whoToFollow}\n";
            }
            return $"Bad form: '{_commandParts}'";
    }
}
