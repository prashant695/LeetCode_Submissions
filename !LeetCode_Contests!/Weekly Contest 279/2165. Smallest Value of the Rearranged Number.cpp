class Solution
{
public:
    long long smallestNumber(long long num)
    {
        vector<long long> v;
        int neg = 0;
        if (num < 0)
            neg = 1;
        num = abs(num);
        if (num == 0)
            return 0;
        long long res = 0, ten = 10;
        string s = "";
        while (num > 0)
        {
            v.push_back(num % 10);
            num /= 10;
        }

        sort(v.begin(), v.end());
        if (neg == 1)
        {
            reverse(v.begin(), v.end());
            for (int i = 0; i < v.size(); i++)
            {
                res = (res * 10) + v[i];
            }
            return res * -1;
        }
        else
        {
            long long j = 0;
            while (j < v.size() and v[j] == 0)
                j++;
            s += (v[j] + '0');
            for (int k = 0; k < v.size(); k++)
                if (v[k] == 0)
                    s += '0', v[k] = -1;

            j += 1;
            for (; j < v.size(); j++)
                if (v[j] != -1)
                    s += (v[j] + '0');

            for (int i = 0; i < s.size(); i++)
                res = (res * 10) + s[i] - '0';

            return res;
        }
    }
};
