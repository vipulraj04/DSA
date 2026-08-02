class Solution {
public:
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        long long maxPair=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int h=gcd(nums[i],nums[j]);
                long long val=1LL*nums[i]*nums[j]/(1LL*h*h);
                maxPair=max(maxPair,val);
            }
        }
        return maxPair;
    }
};