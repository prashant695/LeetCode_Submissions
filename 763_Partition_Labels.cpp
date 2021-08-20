class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        stack<vector<int>>st;
        vector<vector<int>>res;
        for(int i=0;i<v.size();i++)
        {
            if(st.empty()==true) st.push({v[i][0],v[i][1]});
            else if(v[i][0]<=st.top()[1] && v[i][1]>=st.top()[1] ){
                int x = st.top()[0];
                st.pop();
                st.push({x,v[i][1]});
            }
            else if(v[i][0]>st.top()[1]) st.push({v[i][0],v[i][1]});
        }
        while(st.empty()==false)
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        int start[26]={0},end[26]={0};
        for(int i=0;i<s.size();i++)
        {
            if(start[s[i]-'a']==0) start[s[i]-'a']=i+1;
            end[s[i]-'a']=i+1;
        }
        vector<vector<int>>vvv,res;
        for(int i=0;i<26;i++){
            if(start[i])
            {
                 vvv.push_back({start[i],end[i]});
            }
        }
        res = merge(vvv);
        for(int i=res.size()-1;i>=0;i--) {ans.push_back(res[i][1]-res[i][0]+1);}
        return ans;
    }
};