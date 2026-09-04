class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>gt(n);
        gt[0]=nums[0];
        for(int i=1;i<n;i++){
            gt[i]=max(gt[i-1],nums[i]);
        }
        vector<int>st(n);
        st[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            st[i]=min(st[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            int diff=gt[i]-st[i];
            if(diff <= k){
                return i;
            }
        }
        return -1;
    }
};