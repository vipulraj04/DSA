class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>result;
        for(int it : nums){
            if(it<10){
                result.push_back(it);
                continue;
            }

            vector<int>temp;
            while(it){
                temp.push_back(it%10);
                it=it/10;
            }

            for(int i=temp.size()-1;i>=0;i--){
                result.push_back(temp[i]);
            }
        }
        return result;
    }
};