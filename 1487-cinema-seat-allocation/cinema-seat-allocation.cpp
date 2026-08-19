class Solution {
public:
bool helper(unordered_set<int>&st,int start,int end){
    for(int i=start;i<=end;i++){
        if(st.find(i)!=st.end()){
            return false;
        }
    }
    return true;
}
    int maxNumberOfFamilies(int n, vector<vector<int>>& nums) {
        unordered_map<int,unordered_set<int>>mp;
        for(auto &it:nums){
            int u=it[0];
            int v=it[1];

            mp[u].insert(v);
        }

        int result=(n-mp.size())*2;
        for(auto &it : mp){
            bool groupA=helper(it.second,2,5);
            bool groupB=helper(it.second,4,7);
            bool groupC=helper(it.second,6,9);

            if(groupA && groupC){
                result+=2;
            }
            else if(groupA || groupB || groupC){
                result+=1;
            }
        }
        return result;
    }
};