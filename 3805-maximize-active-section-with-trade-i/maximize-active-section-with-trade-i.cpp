class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        int countOne=count(s.begin(),s.end(),'1');
        vector<int>countZero;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int idx=i;
                while(i<n && s[i]== '0')
                    i++;
                    countZero.push_back(i-idx);
            }
            else{
                i++;
            }
        }
        int maxSum=0;
        for(int i=1;i<countZero.size();i++){
            maxSum=max(maxSum,countZero[i]+countZero[i-1]);
        }

        return maxSum+countOne;
    }
};