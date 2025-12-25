class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>result;
        for(int i=0;i<nums.size();i++){
            result[nums[i]]++;
        }

        for(auto it : result){
            if(it.second==1){
                return it.first;
            }
        }
        return 0;
        
    }
};