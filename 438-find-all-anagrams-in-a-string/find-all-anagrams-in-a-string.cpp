class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n=p.length();
        if(s.size() < n) return ans;

        vector<int>Sfreq(26,0);
        vector<int>Pfreq(26,0);

        for(int i=0;i<n;i++){
            Sfreq[s[i]-'a']++;
            Pfreq[p[i]-'a']++;
        }
        if(Sfreq==Pfreq){
            ans.push_back(0);
        }

        for(int i=n;i<s.size();i++){
            Sfreq[s[i]-'a']++;
            Sfreq[s[i-n]-'a']--;

            if(Sfreq==Pfreq){
                ans.push_back(i-n+1);
            }
        }
        return ans;
    }
};