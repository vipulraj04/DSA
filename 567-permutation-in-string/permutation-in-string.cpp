class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n > m){
            return false;
        }
        vector<int>freqS1(26,0);
        for(int i=0;i<n;i++){
            freqS1[s1[i]-'a']++;
        }

        int left=0;
        vector<int>freqS2(26,0);
        for(int right=0;right<n;right++){
            freqS2[s2[right]-'a']++;
        }
        if(freqS1 == freqS2){
            return true;
        }
        for(int right=n;right<m;right++){
            freqS2[s2[left]-'a']--;
            left++;
            freqS2[s2[right]-'a']++;


            if(freqS1 == freqS2){
                return true;
            }
        }
        return false;
    }
};