class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        else if(nums[0]>nums[1]) return nums[1];
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(mid<nums.size()-1 && mid>=1 && nums[mid]>nums[mid+1] && nums[mid-1]<nums[mid])
                return nums[mid+1];
            else if(mid<nums.size()-1 && mid>=1 && nums[mid]<nums[mid+1] && nums[mid-1]>nums[mid])
                return nums[mid];
            else if(mid<nums.size()-1 && nums[mid]<nums[h])
                    h=mid-1;
            else
                    l=mid+1;
        }
            if(nums[0]<nums[nums.size()-1]) return nums[0];
        return nums[nums.size()-1];
    }
};