class Solution {
public:
    bool isPalindrome(string s) {
        string result="";
        for (char ch: s){
            if(isalnum(ch)){
                ch=tolower(ch);
                result+=ch;
            }
        }

        int i=0;
        int j=result.length()-1;
        while(i<j){
            if(result[i]!=result[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};