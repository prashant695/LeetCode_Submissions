class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int r = land.size();
        int c = land[0].size();
        vector<vector<int>> res;
        int a, b;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (land[i][j] == 1)
                {
                    a = i, b = j;
                    while (a < r && land[a][j])
                        a++;
                    while (b < c && land[i][b])
                        b++;

                    for (int k = i; k < a; k++)
                    {
                        for (int l = j; l < b; l++)
                        {
                            land[k][l] = 0;
                        }
                    }

                    res.push_back({i, j, a - 1, b - 1});
                }
            }
        }
        return res;
    }
};
