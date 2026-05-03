class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        if(n!=goal.length()){
            return false;
        }
        string result=s+s;
        for(int i=0;i<n;i++){
            int j=0;
            while(j<n && result[i+j]==goal[j]){
                j++;
            }
            if(j==n){
                return true;
            }
        }
        return false;

    }
};