class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        int i=0;
        int m=s.length();

        while(i<m){
            if(s[i]!=t[i]){
                return t[i];
            }
            i++;
        }
        return t[m];
    }
};