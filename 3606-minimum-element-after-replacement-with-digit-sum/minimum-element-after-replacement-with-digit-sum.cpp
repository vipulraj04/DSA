class Solution {
public:
int sum(int num){
    int res=0;
    while(num){
        int digit=num%10;
        res+=digit;
        num=num/10;
    }
    return res;
}
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int num : nums){
            ans=min(ans,sum(num));
        }
        return ans;
    }
};