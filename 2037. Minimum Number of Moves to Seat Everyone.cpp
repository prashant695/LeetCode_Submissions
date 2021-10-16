class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        int s = 0, n = seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        for (int i = 0; i < n; i++)
            s += abs(students[i] - seats[i]);

        return s;
    }
};