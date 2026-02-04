class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {

        vector<int>result;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        while(j<=n){
            result.push_back(nums[j]);
            result.push_back(nums[i]);

            i+=2;
            j+=2;
        }
        return result;
        
    }
};