class Solution {
public:
int getSum(int num){
    int sum=0;
    while(num){
        sum+=num%10;
        num=num/10;
    }
    return sum;
}
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>newArr(nums);

        auto lambda=[this](int a,int b){
            int digitSuma=getSum(a);
            int digitSumb=getSum(b);

            if(digitSuma != digitSumb){
                return digitSuma < digitSumb;
            }

            return a < b;
        };
        sort(newArr.begin(),newArr.end(),lambda);

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        int count=0;
        for(int i=0;i<n;i++){
            int expected=newArr[i];
            int present=nums[i];

            if(expected==present){
                continue;
            }

            int idx=mp[expected];
            nums[i]=expected;
            nums[idx]=present;

            mp[expected]=i;
            mp[present]=idx;

            count++;
        }

        return count;
    }
};