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
        int n=nums.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            result[i]=sum(nums[i]);
        }

        return *min_element(result.begin(),result.end());

    }
};