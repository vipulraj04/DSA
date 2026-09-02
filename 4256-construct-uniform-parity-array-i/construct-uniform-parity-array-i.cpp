class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        if(n==1){
            return true;
        }
        int even=0;
        int odd=0;
        for(int it : nums1){
            if(it%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        if(even==n || odd==n){
            return true;
        }

        if(even > 0 || odd > 0){
            return true;
        }
        return false;
    }
};