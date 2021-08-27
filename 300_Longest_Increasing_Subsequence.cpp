// Method_1
// O(n*logn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v(nums.size(),1);
        int res=1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    v[i]=max(v[i],v[j]+1);
                    res=max(res,v[i]);
                }
            }
        }
           return res;
    }
};

// Method_2
// O(n*n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            auto it=lower_bound(v.begin(),v.end(),nums[i]);
            if(it==v.end()) v.push_back(nums[i]);
            else *it=nums[i];
        }
        return v.size();
    }
};