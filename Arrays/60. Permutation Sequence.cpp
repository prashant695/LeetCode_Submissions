class Solution
{
public:
    int fact(int n)
    {
        int f = 1;
        for (int i = 1; i <= n; i++)
            f *= i;

        return f;
    }
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return;
        int i = nums.size() - 2;
        while (i >= 0 and nums[i] >= nums[i + 1])
            i--;
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
    string getPermutation(int n, int k)
    {
        int cnt = 1;
        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        while (cnt < k)
        {
            nextPermutation(nums);
            cnt++;
        }

        string s = "";
        for (int i = 0; i < nums.size(); i++)
            s += to_string(nums[i]);

        return s;
    }
};