class Solution {
public:
    bool static cmp(string a, string b)
    {
        if(a.size()!=b.size())
        {
        if(a.size()<b.size())
            return 1;
         else 
             return 0;
        }
         if(a<b) return 1;
        
        return 0;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        reverse(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(k==i+1) return nums[i];
        }
        return "";
    }
};