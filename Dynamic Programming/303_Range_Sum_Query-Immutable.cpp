class NumArray
{
public:
    vector<int> pre_sum;
    NumArray(vector<int> &nums)
    {
        pre_sum.push_back(0);
        pre_sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            pre_sum.push_back(pre_sum[i] + nums[i]);
    }

    int sumRange(int left, int right)
    {
        return (pre_sum[right + 1] - pre_sum[left]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */