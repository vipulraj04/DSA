class Solution {
    public int sortPermutation(int[] nums) {
        int n=nums.length;
        int result=-1;
        for(int i=0;i<n;i++){
            if(i != nums[i]){
                result=result & nums[i];
            }
        }

        return Math.max(0,result);
    }
}