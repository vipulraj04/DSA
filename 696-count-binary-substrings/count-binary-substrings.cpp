class Solution {
public:
    int countBinarySubstrings(string s) {
        int currCount=1;
        int prevCount=0;
        int total=0;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                currCount++;
            }
            else{
                total+=min(currCount,prevCount);
                prevCount=currCount;
                currCount=1;
            }
        }
        return total+=min(currCount,prevCount);
    }
};