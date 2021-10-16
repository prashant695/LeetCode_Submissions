class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int n = colors.size(), alice = 0, bob = 0;
        if (n <= 2)
            return false;
        for (int i = 0; i < colors.size() - 2;)
        {
            if (colors[i] == colors[i + 1] && colors[i + 1] == colors[i + 2])
            {
                char x = colors[i];
                if (colors[i] == 'A')
                    alice++;
                else
                    bob++;
                i += 3;
                while (i < n && colors[i] == x)
                {
                    if (colors[i] == 'A')
                        alice++;
                    else
                        bob++;
                    i++;
                }
            }
            else
                i++;
        }
        // cout<<alice<<" "<<bob<<endl;
        if (alice > bob)
            return true;
        return false;
    }
};