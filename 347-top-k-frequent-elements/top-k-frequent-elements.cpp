class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int it: nums){
            mp[it]++;
        }
        int n=nums.size();
        vector<vector<int>>vec(n+1);

        for(auto & it: mp){
            int val=it.first;
            int freq=it.second;

            vec[freq].push_back(val);
        }
        vector<int>result;
        for(int i=n;i>=0;i--){
            if(vec[i].size()==0)
            continue;

            while(vec[i].size()>0 && k>0){
                result.push_back(vec[i].back());
                vec[i].pop_back();
                k--;
            }
        }
        return result;
    }
};