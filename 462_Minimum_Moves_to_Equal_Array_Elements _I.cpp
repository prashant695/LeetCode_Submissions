class Solution {
public:
    int minMoves2(vector<int>& nums)
    {
       int cnt=0; 
       sort(nums.begin(),nums.end()); 
       for(int i=0;i<nums.size();i++) cnt+=abs(nums[i]-nums[nums.size()/2]); return cnt;  
    }
};