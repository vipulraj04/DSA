class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long allZor=0;
        for(int &num : nums){
            allZor^=num;
        }
        
        int helper=allZor &(-allZor);

        int groupA=0;
        int groupB=0;

        for(int num : nums){
            if(num & helper){
                groupA^=num;
            }
            else{
                groupB^=num;
            }
        }
        return {groupA,groupB};
    }
};