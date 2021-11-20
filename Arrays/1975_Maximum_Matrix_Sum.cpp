class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int minn = INT_MAX, neg = 0, flg = 0;
        long long s = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (minn > abs(matrix[i][j]))
                    minn = abs(matrix[i][j]);
                if (matrix[i][j] < 0)
                    neg++;
                s += abs(matrix[i][j]);
            }
        }
        if (neg % 2 == 0)
            return s;
        else
            return s - 2 * minn;
    }
};