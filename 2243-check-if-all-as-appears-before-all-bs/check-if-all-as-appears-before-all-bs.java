class Solution {
    public boolean checkString(String s) {
        int n=s.length();
        boolean found=false;
        for(int i=0;i<n;i++){
            char ch=s.charAt(i);
            if(ch=='b'){
                found=true;
            }
            else if(ch=='a' && found){
                return false;
            }
        }
        return true;
    }
}