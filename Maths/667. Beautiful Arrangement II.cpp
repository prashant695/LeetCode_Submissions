class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> v;
        for (int i = 0; i < (n - k); i++)
            v.push_back(i + 1);

        int x = k;
        for (int i = 0; i < x; i++)
        {
            if (i % 2 == 0)
                v.push_back(v.back() + k);
            else
                v.push_back(v.back() - k);
            k--;
        }
        return v;
    }
};
