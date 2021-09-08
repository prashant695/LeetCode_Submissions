class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> m;
        int mi = INT_MAX, res = 0;
        for (int i = 0; i < deck.size(); i++)
        {
            m[deck[i]]++;
        }
        for (auto it : m)
        {
            res = gcd(res, it.second);
        }
        return res >= 2;
    }
};