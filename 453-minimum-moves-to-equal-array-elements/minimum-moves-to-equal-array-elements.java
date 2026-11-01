class Solution {
    public int minMoves(int[] nums) {
        int n=nums.length;
        int sum=0;
        int min_ele=Integer.MAX_VALUE;
        for(int x: nums){
            sum+=x;
            min_ele=Math.min(min_ele,x);
        }

        return sum - n*min_ele;
    }
}