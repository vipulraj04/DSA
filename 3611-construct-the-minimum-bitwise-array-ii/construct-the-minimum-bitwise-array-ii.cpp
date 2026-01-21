class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>result;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==2){
                result.push_back(-1);
                continue;
            }
            for(int j=0;j<=32;j++){
                if((nums[i] & (1<<j))>0){
                    continue;
                }
                int prev=j-1;
                int x=nums[i] ^ (1<<(j-1));

                result.push_back(x);
                break;
            }
        }
        return result;
    }
};