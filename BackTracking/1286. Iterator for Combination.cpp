class CombinationIterator
{
public:
    vector<string> res;
    int curr_pos = 0;
    void fun(string characters, int combinationLength, int i, string temp)
    {

        if (temp.size() == combinationLength)
        {
            res.push_back(temp);
            return;
        }
        for (int j = i; characters[j]; j++)
        {
            fun(characters, combinationLength, j + 1, temp + characters[j]);
        }
    }
    CombinationIterator(string characters, int combinationLength)
    {
        fun(characters, combinationLength, 0, "");
    }

    string next()
    {
        if (curr_pos >= res.size())
            return "";
        curr_pos++;
        return res[curr_pos];
    }

    bool hasNext()
    {
        if (curr_pos >= res.size())
            return false;
        return true;
    }
};
