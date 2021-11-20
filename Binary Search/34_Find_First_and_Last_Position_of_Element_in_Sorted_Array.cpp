class Solution
{
public:
    int lower_bound(vector<int> &nums, int target)
    {
        int l = 0, h = nums.size() - 1, mid;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (nums[mid] >= target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return {-1, -1};
        int first = lower_bound(nums, target);
        int second = lower_bound(nums, target + 1) - 1;
        if (first < nums.size() and nums[first] == target)
            return {first, second};
        return {-1, -1};
    }
};
