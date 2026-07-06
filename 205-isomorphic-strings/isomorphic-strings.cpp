class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        vector<int>forS(256,0);
        vector<int>forT(256,0);
        for(int i=0;i<s.length();i++){
            if(forS[s[i]]!=forT[t[i]]){
                return false;
            }
            forS[s[i]]=i+1;
            forT[t[i]]=i+1;
        }
        return true;
    }
};