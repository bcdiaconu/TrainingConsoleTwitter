namespace ConsoleTwitter.Posts;

internal class PostsCollection
{
    private Posts _posts = new Posts();

    internal void Add(Post post)
    => _posts.Add(post);

    internal void Remove(Post post)
    => _posts.Remove(post);

    internal Posts GetPosts()
    => _posts;


    internal Posts FilterUserPosts(string userName)
    => new Posts(_posts.Where(it => it.UserName == userName));
}
