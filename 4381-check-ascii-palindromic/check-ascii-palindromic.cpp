class Solution {
public:
    bool isPalindromic(string s) {
        string temp="";
        for(char ch:s){
            int num=(int)ch;
            temp+=bitset<8>(num).to_string();
        }

        int i=0;
        int j=temp.size()-1;
        while(i<j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};