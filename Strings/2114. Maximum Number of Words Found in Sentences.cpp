class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int cnt = 0, res = 0;
        for (int i = 0; i < sentences.size(); i++)
        {
            cnt = 0;
            for (int j = 0; j < sentences[i].size(); j++)
            {
                if (sentences[i][j] == ' ')
                    cnt++;
            }
            res = max(cnt, res);
        }
        return res + 1;
    }
};