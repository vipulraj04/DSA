class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>nums(arr.begin(),arr.end());
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int rank=1;
        for(int it : nums){
            if(mp.find(it) == mp.end()){
                mp[it]=rank++;
            }
        }
        vector<int>result(n);
        for(int i=0;i<n;i++){
            result[i]=mp[arr[i]];
        }
        return result;
    }
};