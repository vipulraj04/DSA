class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                result[i]=nums[i];
            }

            else{
                int currentIndex=(i+nums[i])%n;
                if(currentIndex<0){
                    currentIndex+=n;
                }


                result[i]=nums[currentIndex];
            }
        }

        return result;
        
    }
};