class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int res;
        res = INT_MAX;
        sort(nums.begin(), nums.end());
 
     for (int i=0; i<=nums.size()-k; i++){
        res = min(nums[i+k-1] - nums[i], res);
     }
 
    return res;
    }
};