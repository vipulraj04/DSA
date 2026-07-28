class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        string left=s.substr(0,n/2);

        sort(left.begin(),left.end());
        string right=left;
        reverse(right.begin(),right.end());

        string mid="";
        if(n%2==1){
            mid+=s[n/2];
        }

        return left+mid+right;
    }
};