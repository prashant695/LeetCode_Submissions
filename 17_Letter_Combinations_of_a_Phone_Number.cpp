class Solution
{
public:
    vector<string> v, res;
    void dfs(string digits, char c, string ans, int idx)
    {
        if (c == '\0')
        {
            res.push_back(ans);
            return;
        }

        for (int i = 0; i < v[c - '0'].size(); i++)
        {
            dfs(digits, digits[idx + 1], ans + v[c - '0'][i], idx + 1);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        v.push_back("");
        v.push_back("");
        v.push_back("abc");
        v.push_back("def");
        v.push_back("ghi");
        v.push_back("jkl");
        v.push_back("mno");
        v.push_back("pqrs");
        v.push_back("tuv");
        v.push_back("wxyz");

        dfs(digits, digits[0], "", 0);
        return res;
    }
};