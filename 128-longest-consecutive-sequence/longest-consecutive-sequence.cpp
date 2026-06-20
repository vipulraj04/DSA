class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int result=0;

        for(int it: st){
            int count=0;
            int largest=0;
            if(st.find(it-1)==st.end()){
                count++;
                largest=it;
                while(st.count(largest+1)){
                    count++;
                    largest++;
                }

                result=max(result,count);
            }
        }
        return result;
    }
};