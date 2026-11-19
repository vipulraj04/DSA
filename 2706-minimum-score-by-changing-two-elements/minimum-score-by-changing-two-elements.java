class Solution {
    public int minimizeSum(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;
        int start=Math.abs(nums[1]-nums[n-2]);
        int end=Math.abs(nums[2]-nums[n-1]);
        int combo=Math.abs(nums[0]-nums[n-3]);

        return Math.min(start,Math.min(end,combo));
        
    }
}