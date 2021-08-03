// Method-1
// Brute Force o(n2)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res;
        int p = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            p = 1;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j)
                {
                    p = p * nums[j];
                }
            }
            res.push_back(p);
        }
        return res;
    }
};

// Method-2
// Using division operator sc-> o(1)  tc-> o(n)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size(), 0);
        int pos, z = 0, p = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                z++, pos = i;
            else
                p *= nums[i];
        }
        if (z == 1)
            res[pos] = p;
        else if (z == 0)
        {
            for (int i = 0; i < nums.size(); i++)
                res[i] = p / nums[i];
        }
        return res;
    }
};
// Method-3
// Without Using division operator sc-> o(n)  tc-> o(n)
// Using extra space
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> left, right, res;
        int p = nums[0];
        int n = nums.size();

        left.push_back(p);
        for (int i = 1; i < n; i++)
            p *= nums[i], left.push_back(p);

        p = nums[n - 1];
        right.push_back(p);
        for (int i = n - 2; i >= 0; i--)
            p *= nums[i], right.push_back(p);
        reverse(right.begin(), right.end());

        res.push_back(right[1]);
        for (int i = 1; i < n - 1; i++)
        {
            res.push_back(left[i - 1] * right[i + 1]);
        }
        res.push_back(left[n - 2]);
        return res;
    }
};
// Method-4
// Without Using division operator sc-> o(1)  tc-> o(n)
// Constant space
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res;
        int p = nums[0];
        int n = nums.size();

        res.push_back(p);
        for (int i = 1; i < n; i++)
            p *= nums[i], res.push_back(p);

        //  for(int i=0;i<n;i++) cout<<res[i]<<" ";
        p = 1;
        for (int i = n - 1; i > 0; i--)
        {
            res[i] = res[i - 1] * p;
            p *= nums[i];
        }

        res[0] = p;
        return res;
    }
};
