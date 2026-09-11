class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int>st;
        int n=digits.size();
        for(int k=0;k<n;k++){
            if(digits[k]%2==1){
                continue;
            }
            for(int j=0;j<n;j++){
                if(j==k){
                    continue;
                }
                for(int i=0;i<n;i++){
                    if(digits[i]==0 || i==j || i==k){
                        continue;
                    }
                    int result=100*digits[k]+10*digits[j]+digits[i];

                    st.insert(result);
                }
            }
        }

        return st.size();
    }
};