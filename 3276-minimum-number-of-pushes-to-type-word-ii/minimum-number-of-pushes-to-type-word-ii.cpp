class Solution {
public:
    int minimumPushes(string word) {
        vector<int>count(26,0);
        for(char ch : word){
            count[ch-'a']++;
        }
        int ans=0;
        sort(count.begin(),count.end(),greater<int>());
        for(int i=0;i<26;i++){
            int freq=count[i];
            int press=(i/8)+1;

            ans+=press*freq;
        }
        return ans;
    }
};