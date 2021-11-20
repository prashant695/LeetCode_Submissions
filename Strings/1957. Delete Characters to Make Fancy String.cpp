class Solution
{
public:
    string makeFancyString(string s)
    {
        string x;
        if (s.size() <= 2)
            return s;

        x = s.substr(0, 2);
        for (int i = 2; i < s.size(); i++)
        {
            if (s[i] == s[i - 1] and s[i - 1] == s[i - 2])
                ;
            else
                x += s[i];
        }
        return x;
    }
};