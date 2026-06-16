class Solution {
public:
    string processStr(string s) {
        string result="";
        for(char ch : s){
            if(ch >= 'a' && ch <= 'z'){
                result+=ch;
            }
            if(ch=='*'){
                if (!result.empty()) {
                    result.pop_back();
                }
            }  
            if(ch=='#'){
                result+=result;
            }

            if(ch=='%'){
                reverse(result.begin(),result.end());
            }
        }
        return result;
    }
};