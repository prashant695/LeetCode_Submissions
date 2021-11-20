class Solution
{
public:
    map<vector<int>, int> m;
    void combin(vector<int> &candidates, vector<int> &tmp, vector<vector<int>> &res, int index, int target)
    {
        if (accumulate(tmp.begin(), tmp.end(), 0) == target)
        {
            sort(tmp.begin(), tmp.end());
            if (m[tmp] == 0)
                res.push_back(tmp), m[tmp] = 1;
            else
                return;
        }
        if (accumulate(tmp.begin(), tmp.end(), 0) > target or index >= candidates.size())
        {
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (i != index && candidates[i] == candidates[index])
                continue;
            tmp.push_back(candidates[i]);
            combin(candidates, tmp, res, i + 1, target);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> tmp;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        combin(candidates, tmp, res, 0, target);
        return res;
    }
};