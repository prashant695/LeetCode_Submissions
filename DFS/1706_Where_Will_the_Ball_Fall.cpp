class Solution
{
public:
    vector<int> res;
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i == grid.size())
        {
            res.push_back(j);
            return 0;
        }
        else if (grid[i][j] == 1)
        {
            if (j + 1 < grid[0].size() && grid[i][j + 1] == 1)
            {
                dfs(i + 1, j + 1, grid);
            }
            else
            {
                res.push_back(-1);
                return 0;
            }
        }
        else if (grid[i][j] == -1)
        {
            if (j >= 1 && grid[i][j - 1] == -1)
            {
                dfs(i + 1, j - 1, grid);
            }
            else
            {
                res.push_back(-1);
                return 0;
            }
        }
        return 0;
    }
    vector<int> findBall(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid[0].size(); i++)
        {
            dfs(0, i, grid);
        }
        return res;
    }
};