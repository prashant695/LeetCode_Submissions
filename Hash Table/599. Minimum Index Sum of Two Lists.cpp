class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> m;
        vector<string> res;
        int minn = INT_MAX;
        for (int i = 0; i < list1.size(); i++)
            m[list1[i]] = i + 1;

        for (int i = 0; i < list2.size(); i++)
            if (m[list2[i]])
                minn = min(m[list2[i]] - 1 + i, minn);

        for (int i = 0; i < list2.size(); i++)
            if (m[list2[i]] and m[list2[i]] - 1 + i == minn)
                res.push_back(list2[i]);
        return res;
    }
};