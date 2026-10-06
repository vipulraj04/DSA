class Solution {
    public int scoreOfParentheses(String s) {
        int score=0;
        int open=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch=s.charAt(i);
            if(ch=='('){
                open++;
            }
            else{
                open--;

                if(s.charAt(i-1)=='(')
                score+=Math.pow(2,open);
            }
        }

        return score;
    }
}