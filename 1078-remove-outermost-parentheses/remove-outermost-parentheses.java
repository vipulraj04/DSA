class Solution {
    public String removeOuterParentheses(String s) {
        int open=0;
        String res="";
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch=s.charAt(i);

            if(ch==')'){
                open--;
            }
            if(open !=0){
                res+=ch;
            }
            if(ch=='('){
                open++;
            }
        }

        return res;
    }
}