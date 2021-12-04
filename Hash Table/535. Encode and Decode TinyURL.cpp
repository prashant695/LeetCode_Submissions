class Solution
{
public:
    map<string, string> encod, decod;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        if (encod[longUrl].size() > 0)
        {
        }
        else
        {
            string s = "http://tinyurl.com/" + to_string(encod.size() + 1);
            encod[longUrl] = s;
            decod[s] = longUrl;
        }
        return encod[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return decod[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
