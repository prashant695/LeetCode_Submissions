class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN;
        int temp=1;
        
        for(int i=0;i<nums.size();i++){ 
            temp*=nums[i];
            res=max({res,temp,nums[i]});
                if(temp==0) 
                    temp=1;
        }
        temp=1;
        for(int i=nums.size()-1;i>=0;i--) {
              temp*=nums[i];
            res=max({res,temp,nums[i]});
                if(temp==0) 
                    temp=1;
        }
        
        return res;
    }
};
