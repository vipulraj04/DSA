class Solution {
    public int getSum(int num){
        int sum=0;
        while(num > 0){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    public int minSwaps(int[] nums) {
        int n=nums.length;
        int [] newArr=nums.clone();

        Integer[] arr=new Integer[n];
        for(int i=0;i<n;i++){
            arr[i]=newArr[i];
        }
        Arrays.sort(arr,(a,b)->{
            int getSuma=getSum(a);
            int getSumb=getSum(b);

            if(getSuma != getSumb){
                return Integer.compare(getSuma,getSumb);
            }

            return Integer.compare(a,b);
        });

        for(int i=0;i<n;i++){
            newArr[i]=arr[i];
        }
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<n;i++){
            mp.put(nums[i],i);
        }
        int count=0;
        for(int i=0;i<n;i++){
            int expected=newArr[i];
            int present=nums[i];

            if(expected==present){
                continue;
            }

            int idx=mp.get(expected);
            nums[i]=expected;
            nums[idx]=present;

            mp.put(expected,i);
            mp.put(present,idx);
            count++;
        }

        return count;
    }
}