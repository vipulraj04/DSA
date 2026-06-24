class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long val=0;
        unordered_map<int,int>mp;
        long long count=0;
        mp[0]=1;
        for(int num : nums){
            val^=num;

            count+=mp[val];

            mp[val]++;
        }
        return count;
    }
};