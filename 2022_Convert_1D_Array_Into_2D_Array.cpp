class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        vector<vector<int>> v;
        if (original.size() != m * n)
            return v;
        int cnt = 0;
        vector<int> sub;
        for (int i = 0; i < m; i++)
        {
            sub.clear();
            for (int j = 0; j < n; j++)
                sub.push_back(original[cnt++]);
            v.push_back(sub);
        }
        return v;
    }
};