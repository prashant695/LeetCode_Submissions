class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int o, e, res = 0, c;
        while (1)
        {
            o = 0, e = 0, c = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > 0)
                    c = 1;
                if (nums[i] & 1)
                    o++;
                else
                    e++;
                nums[i] /= 2;
            }
            if (c == 0)
                break;
            if (o and e)
                res += (o * e);
        }
        return res;
    }
};