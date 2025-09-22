class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>result;

        for(int num : nums){
            result[num]++;
        }
        int maxFreq=0;
        for(auto &it : result){
            maxFreq=max(maxFreq,it.second);
        }

        int ans=0;

        for(auto &it : result){
            if(maxFreq==it.second){
                ans+=it.second;
            }
        }

        return ans;
        
    }
};