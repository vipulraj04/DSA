class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        int count=0;
        int sum=0;
        mp.put(0,1);

        int n=nums.length;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;

            if(rem<0){
                rem=rem+k;
            }

            if(mp.containsKey(rem)){
                count+=mp.get(rem);
            }
            mp.put(rem,mp.getOrDefault(rem,0)+1);
        }
        return count;
    }
}