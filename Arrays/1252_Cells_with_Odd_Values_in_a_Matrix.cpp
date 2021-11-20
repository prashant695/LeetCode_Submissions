class Solution
{
public:
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {
        int a[m][n];
        memset(a, 0, sizeof(a));
        int cnt = 0;
        for (int i = 0; i < indices.size(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[indices[i][0]][j]++;
            }
            for (int j = 0; j < m; j++)
            {
                a[j][indices[i][1]]++;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] & 1)
                    cnt++;
            }
        }
        return cnt;
    }
};