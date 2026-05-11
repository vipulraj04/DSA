class Solution {
public:
vector<int>digit(int num){
    vector<int>helper;
    while(num){
        int rem=num%10;
        helper.push_back(rem);
        num=num/10;
    }
    reverse(helper.begin(),helper.end());
    return helper;
}
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>result;
        for(int it:nums){
            vector<int>vi=digit(it);
        for(int h : vi){
            result.push_back(h);
        }
        }
        return result;
    }
};