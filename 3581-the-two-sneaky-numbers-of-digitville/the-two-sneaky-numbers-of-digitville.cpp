class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        vector<int>ans;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        for(auto & p : freq){
            if(p.second == 2){
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};