class Solution
{
public:
    void combin(int n, int k, int index, vector<int> &temp, vector<vector<int>> &res)
    {
        if (temp.size() == k)
        {
            res.push_back(temp);
            return;
        }
        for (int i = index; i <= n; i++)
        {
            temp.push_back(i);
            combin(n, k, i + 1, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        vector<vector<int>> res;
        combin(n, k, 1, temp, res);
        return res;
    }
};
