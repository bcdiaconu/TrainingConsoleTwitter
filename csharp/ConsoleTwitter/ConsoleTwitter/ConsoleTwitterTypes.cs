namespace ConsoleTwitter;

class Post
{
    public string UserName { get; private set; }
    public string Message { get; private set; }

    public Post(string userName, string message)
    {
        this.UserName = userName;
        this.Message = message;
    }
}

internal class Posts : List<Post>
{
    internal Posts()
        : base() { }

    internal Posts(IEnumerable<Post> posts)
        : base(posts) { }
}

class CommandParts : List<string>
{
    public CommandParts(string[] values)
        : base(values) { }
}

class Users : List<string> { }
