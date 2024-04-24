namespace ConsoleTwitter.Commands;

internal class OutputFormatter
{
    static internal string FormatOutput(string userName, string header, Posts.Posts posts, bool withUser)
    {
        if (posts.Count == 0)
        {
            return $"{userName} {header}\nNo posts found\n";
        }
        else
        {
            if (withUser)
            {
                var formattedPosts = posts.Select(post => $"{post.UserName} - {post.Message}");
                string allPosts = String.Join("\n", formattedPosts);
                return $"{userName} {header}\n{allPosts}\n";
            }
            else
            {
                var formattedPosts = posts.Select(post => $"{post.Message}");
                string allPosts = String.Join("\n", formattedPosts);
                return $"{userName} {header}\n{allPosts}\n";
            }
        }
    }

}
