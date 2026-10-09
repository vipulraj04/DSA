class Solution {
    public int minInsertions(String s) {
        int n=s.length();
        int ans=0;
        Stack<Character>st=new Stack<>();
        for(int i=0;i<n;i++){
            char ch=s.charAt(i);
            if(ch=='('){
                st.push(ch);
            }
            else{
                if(i+1 < n && s.charAt(i+1) ==')'){
                    i++;
                }
                else{
                    ans++;
                }
                if(!st.empty()){
                    st.pop();
                }
                else{
                    ans++;
                }
            }
        }
        return ans+2*st.size();
    }
}