class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(prefix[i]==goal){
                count++;
            }
            int rem=prefix[i]-goal;
            if(mp.count(rem)){
                count+=mp[rem];
            }
            mp[prefix[i]]++;
        }

        return count;
    }
};