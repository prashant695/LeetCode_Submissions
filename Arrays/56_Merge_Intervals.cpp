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
};