class Solution {
    public int minMoves(int[] nums) {
        int max_ele=-1;
        for(int x:nums){
            max_ele=Math.max(x,max_ele);
        }
        int result=0;
        for(int i=0;i<nums.length;i++){
            result+=(max_ele-nums[i]);
        }
        return result;
    }
}