class Solution {
public:
    string largestOddNumber(string num) {
        int idx=-1;
        int n=num.length();
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                idx=i;
                break;
            }
        }
        int i=0;
        return num.substr(i,idx+1);
    }
};