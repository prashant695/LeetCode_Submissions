// Boyer-Moore Voting Algorithm
// t.c-> O(n)   s.c-> O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candid=0,cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0) candid=nums[i];
            
            if(nums[i]==candid) cnt++;
            else cnt--;
        }
        return candid;
    }
};