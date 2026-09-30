class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n=seq.length();

        int [] result=new int[n];

        Stack<Character>st=new Stack<>();

        for(int i=0;i<n;i++){
            char ch=seq.charAt(i);

            if(ch=='('){
                st.push(ch);
                result[i]=st.size()%2;
            }
            else{
                result[i]=st.size()%2;
                st.pop();
            }
        }

        return result;
    }
}