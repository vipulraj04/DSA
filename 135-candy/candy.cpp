class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==0){
            return 0;
        }
        int up=0;
        int down=0;
        int peak=0;
        int result=1;
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                up++;
                peak=up;
                down=0;
                result+=up+1;
            }
            else if(ratings[i]== ratings[i-1]){
                up=down=peak=0;
                result++;
            }
            else{
                down++;
                up=0;
                result+=down;
                if(peak < down){
                    result++;
                }
            }
        }
        return result;
        
    }
};