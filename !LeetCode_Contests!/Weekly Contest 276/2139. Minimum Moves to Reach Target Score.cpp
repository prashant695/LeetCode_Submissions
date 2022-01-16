class Solution
{
public:
    int minMoves(int target, int maxDoubles)
    {

        int cnt = 0;
        while (target != 1)
        {
            if (maxDoubles >= 1)
            {
                if (target % 2 == 1)
                    cnt++, target -= 1;

                target /= 2;
                cnt++;

                maxDoubles--;
            }
            else
            {
                return cnt + target - 1;
            }
        }
        return cnt;
    }
};

