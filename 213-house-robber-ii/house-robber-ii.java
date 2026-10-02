class Solution {
    public int helper(int n,int []nums,int []dp){
        dp[0]=nums[0];

        for(int i=1;i<=n;i++){
            int pick=nums[i];
            if(i > 1){
                pick+=dp[i-2];
            }
            int nPick=dp[i-1];

            dp[i]=Math.max(pick,nPick);
        }

        return dp[n];
    }
    public int rob(int[] nums) {
        int n=nums.length;
        if(n==1){
            return nums[0];
        }
        int [] nums1=new int[n-1];
        int [] nums2=new int[n-1];

        for(int i=1;i<n;i++){
            nums1[i-1]=nums[i];
        }
        for(int i=0;i<n-1;i++){
            nums2[i]=nums[i];
        }

        int dp[]=new int[n+1];
        int dp2[]=new int[n+1];
        Arrays.fill(dp,-1);
        Arrays.fill(dp2,-1);

        int case1=helper(n-2,nums1,dp);
        int case2=helper(n-2,nums2,dp2);

        return Math.max(case1,case2);
    }
}