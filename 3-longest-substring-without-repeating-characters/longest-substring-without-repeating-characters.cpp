class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        int maxLen=0;
        int left=0;
        for(int right=0;right<n;right++){
            if(mp.count(s[right])){
                left=max(left,mp[s[right]]+1);
            }
            
            mp[s[right]]=right;
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};