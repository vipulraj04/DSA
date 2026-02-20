class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        if(t.length()>n){
            return "";
        }
        unordered_map<char,int>mp;
        for(char ch:t){
            mp[ch]++;
        }

        int i=0;
        int requiredCount=t.length();
        int minSize=INT_MAX;
        int start=0;
        int j=0;
        while(j<n){
            char ch=s[j];

            if(mp[ch]>0){
                requiredCount--;
            }
            mp[s[j]]--;

            while(requiredCount==0){
                int currSize=j-i+1;

                if(minSize>currSize){
                    minSize=currSize;
                    start=i;
                }

                mp[s[i]]++;

                if(mp[s[i]]>0){
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        if(minSize==INT_MAX){
            return "";
        }
        else{
            return s.substr(start,minSize);
        }
        
    }
};