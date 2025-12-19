static bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if(a.second==b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>results;

        for(auto it : nums){
            results[it]++;
        } 

        vector<pair<int,int>>count;

        for(auto i: results){
            count.push_back(i);
        }

        sort(count.begin(),count.end(),cmp);

        vector<int>result;
        for(auto re : count){
            for(int i=0;i<re.second;i++){
                result.push_back(re.first);
            }
        }

        return result;

    }
};