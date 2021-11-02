class Solution
{
public:
    int cnt = 0, tot = 0, x, y;
    void solve(int i, int j, vector<vector<int>> &grid, int val, vector<pair<int, int>> v)
    {
        int r = grid.size();
        int c = grid[0].size();
        if (i >= r or j >= c or i < 0 or j < 0 or grid[i][j] == -1)
            return;

        if (val == tot - 1)
        {
            if (i == x and j == y)
            {
                cnt++;
                cout << endl;
            }
            return;
        }

        grid[i][j] = -1;

        solve(i + 1, j, grid, val + 1, v);
        solve(i - 1, j, grid, val + 1, v);
        solve(i, j + 1, grid, val + 1, v);
        solve(i, j - 1, grid, val + 1, v);

        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        vector<pair<int, int>> v;
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] != -1)
                    tot++;
                if (grid[i][j] == 2)
                    x = i, y = j;
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                    solve(i, j, grid, 0, v);
            }
        }
        return cnt;
    }
};