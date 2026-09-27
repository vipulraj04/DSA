class Solution {
    public String reverseParentheses(String s) {
       Stack<Integer>st=new Stack<>();
       String result="";
       int n=s.length();
       for(int i=0;i<n;i++){
        Character ch=s.charAt(i);
        if(ch=='('){
            st.push(result.length());
        }
        else if(ch==')'){
            int len=st.peek();
            st.pop();

            String part=result.substring(len);
            String reversed="";
            for(int j=part.length()-1;j>=0;j--){
                reversed+=part.charAt(j);
            }

            result=result.substring(0,len)+reversed;
        }
        else{
            result+=ch;
        }

       }
       return result;
    }
}