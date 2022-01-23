class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &q)
    {
        int n = arr.size();
        int pre[n];
        vector<int> v;

        pre[0] = arr[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] ^ arr[i];

        for (int i = 0; i < q.size(); i++)
        {
            int x = q[i][0];
            int y = q[i][1];

            if (x == 0)
                v.push_back(pre[y]);
            else
                v.push_back(pre[y] ^ pre[x - 1]);
        }

        return v;
    }
};