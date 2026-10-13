class Solution {
    public long maxAlternatingSum(int[] nums) {
        int n=nums.length;
        if(n==1){
            return nums[0]*nums[0];
        }
        for(int i=0;i<n;i++){
            int ele=nums[i];
            nums[i]=ele*ele;
        }
        Arrays.sort(nums);
        int i=0;
        int j=n-1;
        long suffix=0;
        long preffix=0;
        while(i<=j){
            suffix+=nums[i];
            preffix+=nums[j];
            i++;
            j--;
            if(i==j){
                preffix+=nums[i];
            }
        }
        return preffix-suffix;
    }
}