class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int cnt_o = 0, cnt_z = 0, min_zero, min_one, l, r, win_o, win_z;
       
        // WINDOW FOR 1
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 1)
                cnt_o++;

        l = 0;
        r = cnt_o - 1;

        win_o = 0;

        for (int i = l; i <= r; i++)
            if (nums[i] == 1)
                win_o++;

        min_zero = cnt_o - win_o;

        l++, r++;
        while (r < nums.size())
        {
            if (nums[l - 1] == 1)
                win_o--;
            if (nums[r] == 1)
                win_o++;

            min_zero = min(min_zero, cnt_o - win_o);
            l++;
            r++;
        }


        // WINDOW FOR 0
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 0)
                cnt_z++;

        l = 0;
        r = cnt_z - 1;

        win_z = 0;

        for (int i = l; i <= r; i++)
            if (nums[i] == 0)
                win_z++;

        min_one = cnt_z - win_z;

        l++, r++;
        while (r < nums.size())
        {
            if (nums[l - 1] == 0)
                win_z--;
            if (nums[r] == 0)
                win_z++;

            min_one = min(min_one, cnt_z - win_z);
            l++;
            r++;
        }

        return min(min_zero, min_one);
    }
};