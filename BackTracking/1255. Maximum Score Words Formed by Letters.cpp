class Solution
{
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        int n = pow(2, words.size()), cnt = 0, res = -1;
        vector<int> v(26, 0), v2(26, 0);

        for (int i = 0; i < letters.size(); i++)
            v[letters[i] - 'a']++;

        for (int i = 0; i < n; i++)
        {
            int x = i;
            cnt = 0;
            v2 = v;
            for (int j = 0; j < words.size(); j++)
            {
                if (x & 1)
                {
                    for (int k = 0; k < words[j].size(); k++)
                    {
                        if (v2[words[j][k] - 'a'] >= 1)
                        {
                            cnt += score[words[j][k] - 'a'];
                            v2[words[j][k] - 'a']--;
                        }
                        else
                        {
                            cnt = 0;
                            break;
                        }
                    }
                }
                x /= 2;
                res = max(res, cnt);
            }
        }
        return res;
    }
};
