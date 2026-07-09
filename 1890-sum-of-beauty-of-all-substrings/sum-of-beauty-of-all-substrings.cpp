class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int sum=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int maxI=INT_MIN;
                int minI=INT_MAX;

                for(auto & it: mp){
                    maxI=max(maxI,it.second);
                    minI=min(minI,it.second);
                }

                sum+=(maxI-minI);
            }
        }
        return sum;
    }
};