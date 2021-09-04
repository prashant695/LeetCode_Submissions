class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1) return 0;
        int pre[n],suf[n];
        
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+nums[i];
        }
        
        if(suf[1]==0) return 0;
        
        for(int i=1;i<n-1;i++)
        {
            if(pre[i-1]==suf[i+1]) return i;
        }
        
         
        if(pre[n-2]==0) return n-1;
        return -1;
    }
};