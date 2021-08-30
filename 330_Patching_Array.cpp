class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
       int cnt=1,i=0;
       long long res=0;
       while(1)    
        {
           if(i<nums.size() && res+1>=nums[i])
           {
               res+=nums[i];
               i++;
           }
           else
           {
               if(res>=n) return cnt-1;
               cnt++;
               res+=(res+1);
           }
        }
        return cnt-1;
    }
};