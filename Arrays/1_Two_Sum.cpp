// Basic Approach o(n2)
// Two pass map
// One pass map
// Method 4

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int>v=nums,res(2,-1);
       sort(nums.begin(),nums.end());
       int l=0,h=nums.size()-1;
       while(l<h)
       {
           if(nums[l]+nums[h]==target){break;}
           else if(nums[l]+nums[h]<target){l++;}
           else h--;
       }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[l]==v[i] and res[0]==-1)
                res[0]=i;
            else if(nums[h]==v[i] and res[1]==-1)
                res[1]=i;
        }
        return res;
    }
};
