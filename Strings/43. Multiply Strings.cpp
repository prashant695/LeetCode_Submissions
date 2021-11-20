class Solution
{
public:
    string multiply(string nums1, string nums2)
    {
        if (nums1 == "0" or nums2 == "0")
            return "0";
        int res[1000] = {0}, k = -1, l, carry = 0, sz = -1;
        string s = "";
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            k++;
            l = -1;
            for (int j = nums1.size() - 1; j >= 0; j--)
            {
                l++;
                int x = (nums1[j] - '0') * (nums2[i] - '0');
                int y = x + res[k + l] + carry;
                carry = y / 10;
                y = y % 10;
                res[k + l] = y;
                sz = max(sz, k + l);
            }
            if (carry)
                res[sz + 1] = carry, sz++, carry = 0;
        }
        if (carry)
            res[sz + 1] = carry, sz++;
        for (int i = sz; i >= 0; i--)
            s += to_string(res[i]);
        return s;
    }
};