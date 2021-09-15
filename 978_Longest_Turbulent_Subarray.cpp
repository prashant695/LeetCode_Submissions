class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int ma = 0, ma2 = 0, cnt1 = 1, cnt2 = 1;

        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (i % 2 == 1 && arr[i] > arr[i + 1])
                cnt1++;
            else if (i % 2 == 0 && arr[i] < arr[i + 1])
                cnt1++;
            else
            {
                ma = max(ma, cnt1);
                cnt1 = 1;
            }
        }
        ma = max(ma, cnt1);

        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (i % 2 == 0 && arr[i] > arr[i + 1])
                cnt2++;
            else if (i % 2 == 1 && arr[i] < arr[i + 1])
                cnt2++;
            else
            {
                ma2 = max(ma2, cnt2);
                cnt2 = 1;
            }
        }
        ma2 = max(ma2, cnt2);
        return max(ma, ma2);
    }
};