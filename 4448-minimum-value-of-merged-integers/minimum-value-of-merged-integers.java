class Solution {
    public int minMergedInteger(int[] nums) {
        int ans=Integer.MAX_VALUE;
        int n=nums.length;
        for(int i=0;i<n-1;i+=2){
            String f = String.valueOf(nums[i]);
            String s = String.valueOf(nums[i+1]);

            String res=f+s;

            int result=Integer.parseInt(res);

            ans=Math.min(ans,result);

        }

        return ans;
    }
}