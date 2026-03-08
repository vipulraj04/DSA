class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<int>result;
        int n=nums.size();

        for(string num : nums){
            result.insert(stoi(num,nullptr,2));
        }
        for(int i=0;i<pow(2,n);i++){
            if(result.find(i)==result.end()){
                string temp=bitset<16>(i).to_string();

                return temp.substr(16-n,n);
            }
        }

        return "";
    }
};