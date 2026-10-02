class Solution {
    public int helper(int n,int[] nums,int[] dp){
        if(n ==0){
            return nums[0];
        }
        if(n < 0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int pick=nums[n]+helper(n-2,nums,dp);
        int nPick=0+helper(n-1,nums,dp);

        dp[n]=Math.max(pick,nPick);

        return dp[n];
    }
    public int rob(int[] nums) {
        int n=nums.length;
        if(n==1){
            return nums[0];
        }

        int[] nums1=new int[n-1];
        int[] nums2=new int[n-1];

        for(int i=1;i<n;i++){
            nums1[i-1]=nums[i];
        }
        for(int i=0;i<n-1;i++){
            nums2[i]=nums[i];
        }
        int dp[]=new int[n+1];
        Arrays.fill(dp,-1);
        int dp1[]=new int[n+1];
        Arrays.fill(dp1,-1);

        int case1=helper(n-2,nums1,dp);
        int case2=helper(n-2,nums2,dp1);


        return Math.max(case1,case2);
    }
}