class Solution
{
public:
    bool isPrefixString(string s, vector<string> &words)
    {
        string temp = "";
        for (int i = 0; i < words.size(); i++)
        {
            if (temp.size() + words[i].size() <= s.size())
                temp += words[i];
            else
            {
                return s == temp;
            }
        }
        return s == temp;
    }
};