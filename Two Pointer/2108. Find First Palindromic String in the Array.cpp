class Solution
{
public:
    int ispali(string s)
    {
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
                return 0;
        }
        return 1;
    }
    string firstPalindrome(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            if (ispali(words[i]))
                return words[i];
        }
        return "";
    }
};