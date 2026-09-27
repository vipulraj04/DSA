class Solution {
public:
    string reverseParentheses(string s) {
        string result="";
        stack<int>st;
        for(char &ch: s){
            if(ch=='('){
                st.push(result.length());
            }
            else if(ch==')'){
                int len=st.top();
                st.pop();

                reverse(result.begin()+len,result.end());
            }
            else{
                result+=ch;
            }
        }

        return result;
    }
};