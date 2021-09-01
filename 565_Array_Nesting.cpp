class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<int>visited(nums.size(),0);
        int cnt=0,res=-1,j;
        
        for(int i=0;i<nums.size();i++)
        {
            cnt=0;
            if(visited[nums[i]]==0)
            {
                visited[nums[i]]=1;
                cnt++;
                j=nums[nums[i]];
                while(visited[j]==0)
                {
                    visited[j]=1;
                    cnt++;
                    j=nums[j];
                }
                
                res=max(cnt,res);
            }
        }
        return res;
    }
};