class Solution {
    public boolean checkString(String s) {
        int n=s.length();
        int lastA=-1;
        int firstB=-1;
        for(int i=0;i<n;i++){
            char ch=s.charAt(i);
            if(ch=='a'){
                lastA=i;
            }
        }
        for(int i=0;i<n;i++){
            char ch=s.charAt(i);
            if(ch=='b'){
                firstB=i;
                break;
            }
        }
        if(firstB==-1){
            return true;
        }
        return firstB> lastA;
    }
}