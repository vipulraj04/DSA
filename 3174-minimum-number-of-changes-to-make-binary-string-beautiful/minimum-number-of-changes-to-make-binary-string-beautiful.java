class Solution {
    public int minChanges(String s) {
        int n=s.length();
        int result=0;
        for(int i=0;i<n;i+=2){
            char ch=s.charAt(i);
            char chN=s.charAt(i+1);
            if(ch!=chN){
                result++;
            }
        }
        return result;
    }
}