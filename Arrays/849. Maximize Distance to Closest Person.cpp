class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int cnt = 0, res = 0, res2 = 0;
        int a = -1;

        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 1 and a == -1)
                a = i;

            else if (seats[i] == 1 and a != -1)
                cnt = max(cnt, (i - a) / 2), a = i;
        }

        a = 0;
        while (seats[a] != 1)
            res++, a++;

        a = seats.size() - 1;
        while (seats[a] != 1)
            res2++, a--;

        return max(cnt, max(res, res2));
    }
};