class Solution
{
public:
    int fun(string a, int k, int flg)
    {
        char c;
        int n = a.size();
        if (flg == 0)
            c = 'T';
        else
            c = 'F';
        int cnt_false = 0, l = 0, len = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == c)
            {
                cnt_false++;
            }

            while (cnt_false > k)
            {
                if (a[l] == c)
                {
                    cnt_false -= 1;
                }
                l += 1;
            }
            if (i - l + 1 > len)
                len = i - l + 1;
        }

        return len;
    }

    int maxConsecutiveAnswers(string answerKey, int k)
    {
        return max(fun(answerKey, k, 0), fun(answerKey, k, 1));
    }
};
