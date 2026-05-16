class Solution {
public:
    int minBitFlips(int start, int goal) {
       int xr=start ^ goal;
       int count=0;
       while(xr>0){
        if(xr &1){
            count++;
        }
        xr =xr >>1;
       } 

       return count;
    }
};