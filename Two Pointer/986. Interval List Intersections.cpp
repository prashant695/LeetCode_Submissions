class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> res;
        vector<int> v;
        int x = 0, y = 0;
        while (x < A.size() and y < B.size())
        {
            if (B[y][0] <= A[x][1] and A[x][0] <= B[y][1])
            {
                v.clear();
                v.push_back(max(A[x][0], B[y][0]));
                v.push_back(min(A[x][1], B[y][1]));
                res.push_back(v);
            }
            if (A[x][1] <= B[y][1])
                x++;
            else
                y++;
        }
        return res;
    }
};