// Method_0
// BruteForce
// tc - O(2^n)
class Solution
{
public:
    int res = 0;
    void dfs(vector<int> &piles, int i, int j, int alex, int lee, int turn)
    {
        if (i == j)
        {
            if (turn % 2 == 0)
                alex += piles[i];
            else
                lee += piles[j];
            if (alex > lee)
                res = 1;
            return;
        }
        turn++;
        if (turn % 2 == 1)
        {
            dfs(piles, i + 1, j, alex + piles[i], lee, turn);
            dfs(piles, i, j - 1, alex + piles[j], lee, turn);
        }
        else
        {
            dfs(piles, i + 1, j, alex, lee + piles[i], turn);
            dfs(piles, i, j - 1, alex, lee + piles[j], turn);
        }
    }
    bool stoneGame(vector<int> &piles)
    {
        int j = piles.size() - 1;
        dfs(piles, 0, j, 0, 0, 0);
        return res == 1;
    }
};

// Method_1
// Memoization
// tc - O(n2)  sc - O(n2)
class Solution
{
public:
    int dp[501][501];
    int fun(vector<int> &piles, int i, int j)
    {
        if (i == j)
        {
            return piles[i];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = max(piles[i] - fun(piles, i + 1, j), piles[j] - fun(piles, i, j - 1));
    }
    bool stoneGame(vector<int> &piles)
    {
        memset(dp, -1, sizeof(dp));
        return fun(piles, 0, piles.size() - 1) > 0;
    }
};

// Method_2
// Tricky Part O(1)
// How To Proceed
/*
It is given that the number of piles would be even i.e Alex and Lee would be able
to pick up the equal number of piles (total piles is 4, then 2 for alex and 2 for lee)
Also, the sum of stones in total is odd i.e either of the two piles that goes to alex or lee
contains the more number of stones as compare to the other
Since Alex turn's is first, latter would choose either of all the even number of piles
or all th odd number
 of piles, and it's obvious that alex would choose the pile containing
the more stones
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
         return true;   
    }
};
