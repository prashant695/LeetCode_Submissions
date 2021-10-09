class Solution
{
public:
    int vis[14][14];
    bool help(vector<vector<char>> &board, const string &word, string res, int i, int j, int x)
    {
        if (res == word)
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || x >= word.size())
            return false;
        if (vis[i][j] || board[i][j] != word[x])
            return false;
        vis[i][j] = 1;
        bool tt = help(board, word, res + board[i][j], i + 1, j, x + 1) || help(board, word, res + board[i][j], i - 1, j, x + 1) || help(board, word, res + board[i][j], i, j + 1, x + 1) || help(board, word, res + board[i][j], i, j - 1, x + 1);

        vis[i][j] = 0;
        return tt;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> res;
        memset(vis, 0, sizeof(vis));
        for (int k = 0; k < words.size(); k++)
        {
            for (int i = 0; i < board.size(); i++)
            {
                for (int j = 0; j < board[0].size(); j++)
                {
                    string s = words[k];
                    reverse(s.begin(), s.end());
                    if (help(board, s, "", i, j, 0))
                    {
                        res.push_back(words[k]);
                        i = board.size();
                        j = board[0].size();
                    }
                }
            }
        }
        return res;
    }
};
