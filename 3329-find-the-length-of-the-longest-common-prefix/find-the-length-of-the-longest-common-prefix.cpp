class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(int num : arr1){
            while(num){
                st.insert(num);
                num=num/10;
            }
        }
        int maxLength=0;
        for(int num : arr2){
            while(num){
                if(st.count(num)){
                    maxLength=max(maxLength,(int)log10(num)+1);
                    break;
                }
                num=num/10;
            }
        }

        return maxLength;
    }
};