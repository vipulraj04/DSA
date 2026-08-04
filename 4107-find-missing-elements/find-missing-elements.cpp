class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());

        unordered_set<int>st;
        for(int it:nums){
            st.insert(it);
        }
        vector<int>result;
        int i=mini;
        while(i<maxi){
            if(!st.count(i)){
                result.push_back(i);
            }
            i++;
        }
        sort(result.begin(),result.end());
        return result;
    }
};