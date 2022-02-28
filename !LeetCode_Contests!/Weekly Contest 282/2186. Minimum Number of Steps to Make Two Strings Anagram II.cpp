class Solution
{
public:
    int minSteps(string s, string t)
    {
        map<char, long long int> m1, m2;
        long long int cnt = 0;
        for (auto x : s)
            m1[x]++;
        for (auto y : t)
            m2[y]++;

        for (int i = 0; i < 26; i++)
        {
            cnt += abs(m1[i + 'a'] - m2[i + 'a']);
        }
        return cnt;
    }
};