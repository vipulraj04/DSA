class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int maxFreq=0;
        int maxLength=0;
        vector<int>mp(26,0);
        for(int right=0;right<s.length();right++){
            mp[s[right]-'A']++;
            maxFreq=max(maxFreq,mp[s[right]-'A']);
            while((right-left +1)-maxFreq > k){
                mp[s[left]-'A']--;
                left++;
            }

            maxLength=max(maxLength,right-left +1);
        }
        return maxLength;
    }
};