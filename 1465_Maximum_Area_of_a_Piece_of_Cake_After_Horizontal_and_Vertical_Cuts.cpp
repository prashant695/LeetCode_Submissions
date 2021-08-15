class Solution
{
public:
    int maxArea(int h, int w, vector<int> &v1, vector<int> &v2)
    {
        long long mod = 10e9 + 7, res, res1 = -1, res2 = -1;
        v1.push_back(0);
        v2.push_back(0);
        v1.push_back(h);
        v2.push_back(w);
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for (int i = 1; i < v1.size(); i++)
            res1 = max(res1 * 1ll, 1ll * v1[i] - v1[i - 1]);
        for (int i = 1; i < v2.size(); i++)
            res2 = max(res2 * 1ll, 1ll * v2[i] - v2[i - 1]);
        return (res1 % (1000000000 + 7) * res2 % (1000000000 + 7)) % (1000000000 + 7);
    }
};