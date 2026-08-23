class Solution {
public:
    bool sumGame(string num) {
        int count1=0;
        int count2=0;
        int sum=0;
        int n=num.length();
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(num[i]=='?'){
                    count1++;
                }
                else{
                    sum+=num[i]-'0';
                }
            }
            else{
                if(num[i]=='?'){
                    count2++;
                }
                else{
                    sum-=num[i]-'0';
                }
            }
        }

        if((count1+count2)%2!=0){
            return true;
        }
        int ans=sum+(count1/2)*9-(count2/2)*9;

        return ans!=0;
    }
};