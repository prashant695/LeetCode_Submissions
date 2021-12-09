class Solution
{
public:
    vector<int> vis;
    bool dfs(vector<int> &arr, int i)
    {
        if (i < 0 or i >= arr.size() or vis[i] == 1)
            return 0;
        if (arr[i] == 0)
            return 1;
        vis[i] = 1;
        return (dfs(arr, i + arr[i]) or dfs(arr, i - arr[i]));
    }
    bool canReach(vector<int> &arr, int start)
    {
        for (int i = 0; i < arr.size(); i++)
            vis.push_back(0);
        return dfs(arr, start);
    }
};