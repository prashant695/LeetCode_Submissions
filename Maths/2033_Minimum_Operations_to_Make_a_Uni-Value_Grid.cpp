class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> nums;
        int cnt = 0;
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                nums.push_back(grid[i][j]);
        sort(nums.begin(), nums.end());
        int n = nums[(r * c) / 2];

        for (int i = 0; i < nums.size(); i++)
        {
            if (abs(nums[i] - n) % x != 0)
                return -1;
            cnt += abs(nums[i] - n) / x;
        }
        return cnt;
    }
};