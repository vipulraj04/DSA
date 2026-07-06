class Solution {
public:
    bool rotateString(string s, string g) {
        if(s.length()!=g.length()){
            return false;
        }
        string newString=s+s;
        return newString.find(g) !=string::npos;
    }
};