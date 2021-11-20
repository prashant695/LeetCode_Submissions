class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int l = 0, h = nums.size() - 1, mid;
        while (l < h)
        {
            mid = l + (h - l) / 2;
            if (mid == 0 and nums[mid] != nums[mid + 1])
                return nums[mid];
            else if (mid == nums.size() - 1 and nums[mid] != nums[mid - 1])
                return nums[mid];
            else if (nums[mid] != nums[mid + 1] and nums[mid] != nums[mid - 1])
                return nums[mid];
            else if (nums[mid] == nums[mid - 1] and mid % 2 == 0)
                h = mid - 1;
            else if (nums[mid] == nums[mid + 1] and mid % 2 == 1)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return nums[l];
    }
};
