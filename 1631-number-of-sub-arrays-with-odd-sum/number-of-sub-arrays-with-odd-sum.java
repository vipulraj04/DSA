class Solution {
    long mod=1000000007;
    public int numOfSubarrays(int[] arr) {
        long even=1;
        long odd=0;
        long ans=0;
        
        long sum=0;
        for(int x : arr){
            sum+=x;
            if(sum % 2==0){
                ans=(ans+odd)%mod;
                even++;
            }
            else{
                ans=(ans+even)%mod;
                odd++;
            }
        }
        return (int)ans;
    }
}