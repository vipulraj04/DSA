class Solution {
public:
int binarySearch(vector<int>&potions,long long success,int spell){
    int start=0;
    int end=potions.size()-1;
    int ans=potions.size();

    while(start<=end){
        int mid=start+(end-start)/2;
        if(1LL*spell*potions[mid]>=success){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    return ans;
}
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        vector<int>result;
        int m=potions.size();
        for(int spell : spells){
            int index=binarySearch(potions,success,spell);

            result.push_back(m-index);
        }

        return result;
    }
};