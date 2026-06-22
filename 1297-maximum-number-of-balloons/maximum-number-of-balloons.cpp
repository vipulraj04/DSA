class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        for(char ch:text){
            mp[ch]++;
        }

        string target="balloon";
        int maxans=INT_MAX;
        for(char ch: target){
            auto it=mp.find(ch);

            if(it==mp.end()){
                return 0;
            }

            int freq=it->second;

            if(ch=='l' || ch=='o'){
                freq=freq/2;
            }
            maxans=min(maxans,freq);
        }
        return maxans;
    }
};