class Solution
{
public:
    bool checkValid(vector<vector<int>> &v)
    {
        int r = v.size(), c = v[0].size(), x;

        for (int i = 0; i < c; i++)
        {
            x = 0;
            for (int j = 0; j < r; j++)
            {
                x ^= (j + 1);
                x ^= v[j][i];
            }
            if (x)
                return 0;
        }
        for (int i = 0; i < r; i++)
        {
            x = 0;
            for (int j = 0; j < c; j++)
            {
                x ^= (j + 1);
                x ^= v[i][j];
            }
            if (x)
                return 0;
        }

        return 1;
    }
};