class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorSum=0;
        int n=nums.size();
        bool foundZero=true;
        for(int it:nums){
            xorSum=(xorSum ^ it);
            if(it!=0){
                foundZero=false;
            }
        }

        if(foundZero){
            return 0;
        }
        if(xorSum ==0){
            return n-1;
        }
        return n;
    }
};