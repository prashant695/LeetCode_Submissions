class Solution
{
public:
    string tictactoe(vector<vector<int>> &moves)
    {
        int mat[3][3];
        int flg = 0;
        memset(mat, -1, sizeof(mat));
        for (int i = 0; i < moves.size(); i++)
        {
            if (flg % 2 == 0)
            {
                mat[moves[i][0]][moves[i][1]] = 1;
            }
            else
            {
                mat[moves[i][0]][moves[i][1]] = 0;
            }
            if ((mat[0][0] == mat[0][1] && mat[0][1] == mat[0][2]) ||
                (mat[0][0] == mat[1][0] && mat[1][0] == mat[2][0]) ||
                (mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2]))
            {
                if (mat[0][0] == 1)
                    return "A";
                else if (mat[0][0] == 0)
                    return "B";
            }
            else if ((mat[0][2] == mat[1][2] && mat[1][2] == mat[2][2]) ||
                     (mat[2][0] == mat[2][1] && mat[2][1] == mat[2][2]))
            {
                {
                    if (mat[2][2] == 1)
                        return "A";
                    else if (mat[2][2] == 0)
                        return "B";
                }
            }
            else if (mat[1][0] == mat[1][2] && mat[1][2] == mat[1][1])
            {
                {
                    if (mat[1][1] == 1)
                        return "A";
                    else if (mat[1][1] == 0)
                        return "B";
                }
            }
            else if (mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0])
            {
                if (mat[0][2] == 1)
                    return "A";
                else if (mat[0][2] == 0)
                    return "B";
            }
            else if (mat[0][1] == mat[1][1] && mat[1][1] == mat[2][1])
            {
                if (mat[0][1] == 1)
                    return "A";
                else if (mat[0][1] == 0)
                    return "B";
            }
            flg++;
        }
        if (moves.size() == 9)
            return "Draw";
        return "Pending";
    }
};