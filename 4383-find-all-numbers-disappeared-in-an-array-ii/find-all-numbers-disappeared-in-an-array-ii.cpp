class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int>mp(nums.begin(),nums.end());
        vector<int>miss;
        for(int i=lower;i<=upper;i++){
            if(!mp.count(i)){
                miss.push_back(i);
            }
        }
        vector<vector<int>>result;
        if(miss.empty()){
            return result;
        }
        int temp=miss[0];
        for(int i=0;i<miss.size()-1;i++){
            if(miss[i+1]-miss[i] != 1){
                result.push_back({temp,miss[i]});
                temp=miss[i+1];
            }
        }
        result.push_back({temp, miss.back()});
        return result;
    }
};