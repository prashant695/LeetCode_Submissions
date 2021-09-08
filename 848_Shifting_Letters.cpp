class Solution
{
public:
    string shiftingLetters(string s, vector<int> &shifts)
    {
        string res = "";
        int n = s.size();
        suff = shifts[n - 1];

        for (int i = 0; i < s.size(); i++)
        {
            res += ((s[i] - 'a') + (suff)) % 26 + 'a';
            suff +=
        }
        return res;
    }
};