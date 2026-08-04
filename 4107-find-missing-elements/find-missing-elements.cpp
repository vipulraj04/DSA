class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());

        vector<int>count(101,0);
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }

        vector<int>result;
        for(int i=mini;i<maxi;i++){
            if(count[i]==0){
                result.push_back(i);
            }
        }

        sort(result.begin(),result.end());
        return result;
    }
};