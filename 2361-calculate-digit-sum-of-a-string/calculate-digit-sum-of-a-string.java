class Solution {
    public String digitSum(String s, int k) {
        int n=s.length();
        
        while(n > k){
            int equal=n/k;
            int rem=n%k;
            String result="";

            for(int i=0;i<equal;i++){
                int sum=0;
                for(int j=i*k;j<(i+1)*k;j++){
                    sum+=s.charAt(j)-'0';
                }
                result+=sum;
            }

            if(rem!=0){
                int sum=0;
                for(int i=equal*k;i<n;i++){
                    sum+=s.charAt(i)-'0';
                }
                result+=sum;
            }
            s=result;
            n=s.length();
        }
        return s;
    }
}