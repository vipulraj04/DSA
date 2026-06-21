class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=0;
        int count1=0;

        int ele2=0;
        int count2=0;

        for(int num : nums){
            if(num==ele1){
                count1++;
            }
            else if(num==ele2){
                count2++;
            }
            else if(count1==0){
                ele1=num;
                count1++;
            }
            else if(count2==0){
                ele2=num;
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        count1=0;
        count2=0;
        for(int it : nums){
            if(it==ele1){
                count1++;
            }
            else if(it== ele2){
                count2++;
            }
        }
        vector<int>result;
        int cutOff=nums.size()/3;
        if(count1 > cutOff){
            result.push_back(ele1);
        }
        if(count2 > cutOff){
            result.push_back(ele2);
        }
        return result;
    }
};