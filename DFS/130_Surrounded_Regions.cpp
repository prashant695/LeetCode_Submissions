class Solution
{
public:
    int vis[201][201];
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        int r = board.size();
        int c = board[0].size();
        if (i < 0 or j < 0 or i >= r or j >= c or vis[i][j] or board[i][j] != 'O')
            return;

        vis[i][j] = 1;
        board[i][j] = '&';

        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
    void solve(vector<vector<char>> &board)
    {
        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if ((i == 0 or j == 0 or i == r - 1 or j == c - 1) and (board[i][j] == 'O'))
                    dfs(board, i, j);
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == '&')
                    board[i][j] = 'O';
            }
        }
    }
};