class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>result;
        for(int num : nums){
            if(num % 2==0){
                result.push_back(-1);
                continue;
            }
            for(int x=0;x<num;x++){
                if((x|x+1)==num){
                    result.push_back(x);
                    break;
                }
            }
        }

        return result;
        
    }
};