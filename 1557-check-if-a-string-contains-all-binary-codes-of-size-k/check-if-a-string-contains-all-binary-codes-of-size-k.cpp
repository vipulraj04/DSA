#include<bits/stdc++.h>
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int code=pow(2,k);
        unordered_set<string>st;
        for(int i=k;i<=s.length();i++){
            st.insert(s.substr(i-k,k));
        }

        if(st.size()==code){
            return true;
        }
        return false;
    }
};