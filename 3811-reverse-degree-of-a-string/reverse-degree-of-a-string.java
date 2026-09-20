class Solution {
    public int reverseDegree(String s) {
        int n=s.length();
        int totalSum=0;
        for(int i=0;i<n;i++){
            int diff=123-s.charAt(i);

            int pos=i+1;

            totalSum+=diff*pos;
        }

        return totalSum;
    }
}