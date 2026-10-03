class Solution {
    public int longestValidParentheses(String s) {
        int n=s.length();
        if(n==0 || n==1){
            return 0;
        }
        int open=0;
        int close=0;
        int result=0;
        for(int i=0;i<n;i++){
            char ch=s.charAt(i);

            if(ch=='('){
                open++;
            }
            else{
                close++;
            }

            if(close > open){
                open=0;
                close=0;
            }
            else if(close==open){
                result=Math.max(result,open+close);
            }
        }
        open=0;
        close=0;
        for(int i=n-1;i>=0;i--){
            char ch=s.charAt(i);
            if(ch=='('){
                open++;
            }
            else{
                close++;
            }

            if(open > close){
                open=0;
                close=0;
            }
            else if(open==close){
                result=Math.max(result,open+close);
            }
        }

        return result;
    }
}