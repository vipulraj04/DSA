class Solution {
    public long countCommas(long n) {
        long start=1000;
        long ans=0;
        while(start <=n){
            ans+=(n-start+1);
            start=start*1000;
        }

        return ans;
    }
}