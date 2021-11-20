class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i + 1; j < matrix[i].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size() / 2; j++)
            {
                swap(matrix[i][j], matrix[i][matrix.size() - 1 - j]);
            }
        }
    }
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        for (int i = 0; i < 4; i++)
        {
            rotate(mat);
            if (mat == target)
                return true;
        }
        return false;
    }
};