class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        stringstream obj1(a),obj2(b),res;
        int i,j,k,l;
        char c;
        obj1>>i>>c>>j>>c;
        obj2>>k>>c>>l>>c;
        res<<(i*k-j*l)<<'+'<<(j*k+i*l)<<c;
        return res.str();    
    }
};
