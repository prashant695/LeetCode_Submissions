class Solution
{
public:
    int cnt = 0;
    void fun(vector<int> &nums, int x)
    {
        if (x == nums.size())
        {
            cnt++;
        }

        for (int i = x; i < nums.size(); i++)
        {
            swap(nums[i], nums[x]);
            if ((nums[x] % (x + 1) == 0) or (x + 1) % nums[x] == 0)
                fun(nums, x + 1);
            swap(nums[i], nums[x]);
        }
    }
    int countArrangement(int n)
    {
        vector<int> v;
        for (int i = 1; i <= n; i++)
            v.push_back(i);
        fun(v, 0);
        return cnt;
    }
};
