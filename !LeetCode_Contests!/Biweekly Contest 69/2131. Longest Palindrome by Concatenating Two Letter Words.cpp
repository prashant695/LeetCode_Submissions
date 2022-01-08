class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        map<string, int> m;
        int cnt = 0, flg = 0;

        for (int i = 0; i < words.size(); i++)
            m[words[i]]++;

        for (int i = 0; i < words.size(); i++)
        {
            if (m[words[i]] and words[i][0] == words[i][1])
            {
                if (m[words[i]] % 2 == 0)
                    cnt += m[words[i]] * 2;

                else if (m[words[i]] % 2 == 1)
                {
                    if (flg == 0)
                    {
                        cnt += m[words[i]] * 2;
                        flg = 1;
                    }
                    else
                    {
                        cnt += (m[words[i]] - 1) * 2;
                    }
                }

                m[words[i]] = 0;
            }
            else
            {
                string s = words[i];
                reverse(s.begin(), s.end());
                if (m[s])
                    cnt += 2, m[s]--;
            }
        }
        return cnt;
    }
};