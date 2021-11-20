// Method_1
// map<string,vector<string>>m;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> m;
        vector<vector<string>> vv;
        string x;
        for (int i = 0; i < strs.size(); i++)
        {
            x = strs[i];
            sort(x.begin(), x.end());
            m[x].push_back(strs[i]);
        }

        for (auto it : m)
        {
            vv.push_back(it.second);
        }
        return vv;
    }
};

// Method_1
// vector<pair<string, int>> v;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<pair<string, int>> v;
        vector<string> sub;
        vector<vector<string>> vv;
        string x;
        for (int i = 0; i < strs.size(); i++)
        {
            x = strs[i];
            sort(x.begin(), x.end());
            v.push_back({x, i});
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < v.size() - 1; i++)
        {
            sub.push_back(strs[v[i].second]);
            if (v[i].first != v[i + 1].first)
            {
                vv.push_back(sub);
                sub.clear();
            }
        }
        sub.push_back(strs[v[v.size() - 1].second]);
        vv.push_back(sub);
        return vv;
    }
};