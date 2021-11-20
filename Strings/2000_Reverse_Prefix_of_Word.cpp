class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int pos = -1;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ch)
            {
                pos = i;
                break;
            }
        }
        string t = "";
        if (pos == -1)
            return word;
        for (int i = pos; i >= 0; i--)
        {
            t += word[i];
        }

        for (int i = pos + 1; i < word.size(); i++)
        {
            t += word[i];
        }
        return t;
    }
};