class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>v;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        for(auto it:m)
            pq.push({it.second,it.first});
        
        for(int i=0;i<k;i++)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};