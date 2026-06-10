class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>preffix(n);
        preffix[0]=nums[0];
        for(int i=1;i<n;i++){
            preffix[i]=preffix[i-1]+nums[i];
        }

        int count=0;
        unordered_map<int,int>mp;
        for(int j=0;j<n;j++){
            if(preffix[j]==k){
                count++;
            }

            int res=preffix[j]-k;

            if(mp.find(res)!=mp.end()){
                count+=mp[res];
            }

            mp[preffix[j]]++;
        }
        return count;
    }
};