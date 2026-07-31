class Solution {
public:
    int minimumPushes(string word) {
        vector<int>count(26,0);
        for(char ch: word){
            count[ch-'a']++;
        }
        sort(count.begin(),count.end(),greater<int>());

        int result=0;
        for(int i=0;i<26;i++){
            int freq=count[i];
            int press=(i/8)+1;

            result+=freq*press;
        }
        return result;
    }
};