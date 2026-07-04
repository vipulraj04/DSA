class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string result="";
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='('){
                if(st.empty()){
                    st.push(ch);
                }
                else{
                    st.push(ch);
                    result+=ch;
                }
            }
            else{
                st.pop();
                if(!st.empty()){
                    result+=ch;
                }
            }
        }
        return result;
    }
};