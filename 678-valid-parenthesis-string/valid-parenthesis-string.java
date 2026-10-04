class Solution {
    public boolean checkValidString(String s) {
       int ltrCount=0;
       int rtlCount=0;
       int n=s.length();
       for(int i=0;i<n;i++){
        Character ch=s.charAt(i);
        if(ch=='(' || ch=='*'){
            ltrCount++;
        }
        else{
            ltrCount--;
        }

        if(ltrCount < 0){
            return false;
        }
       } 

       for(int i=n-1;i>=0;i--){
        Character ch=s.charAt(i);
        if(ch==')' || ch=='*'){
            rtlCount++;
        }
        else{
            rtlCount--;
        }

        if(rtlCount < 0){
            return false;
        }
       }

       return true;
    }
}