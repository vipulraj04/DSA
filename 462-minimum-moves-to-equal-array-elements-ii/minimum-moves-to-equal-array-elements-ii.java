class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;
        int digit=nums[n/2];

        int result=0;
        for(int i=0;i<n;i++){
            if(digit > nums[i]){
                result+=digit-nums[i];
            }
            else{
                result+=nums[i]-digit;
            }
        }

        return result;
    }
}