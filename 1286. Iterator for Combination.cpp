class CombinationIterator {
public:
    vector<string>v;
    int k=0;
    void fun(string s, int i, string t, int num)
    {

        if(t.size()==num)
        {
            v.push_back(t);
            return;
        }
        for(int j=i;s[j];j++){
            fun(s, j+1, t+s[j], num);
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        fun(characters, 0, "", combinationLength);
    }
    
    string next() {
        if(k<v.size()) 
            return v[k++];
        return "";
    }
    
    bool hasNext() {
        if(k<v.size())
           return 1;
        return 0;
    }
};
