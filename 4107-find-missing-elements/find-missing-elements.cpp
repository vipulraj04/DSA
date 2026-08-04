class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());

        set<int>st(nums.begin(),nums.end());
        vector<int>result;
        for(int i=mini+1;i<maxi;i++){
            if(!st.count(i)){
                result.push_back(i);
            }
        }
        return result;
    }
};