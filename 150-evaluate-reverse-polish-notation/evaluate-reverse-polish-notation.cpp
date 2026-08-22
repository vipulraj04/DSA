class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string ch : tokens){
            if(isdigit(ch[0]) || ch.size() > 1 && ch[0]=='-'){
                st.push(stoi(ch));
            }

            else{
                int b=st.top();
                st.pop();

                int a=st.top();
                st.pop();

                if(ch=="+"){
                    st.push(a+b);
                }

                else if(ch=="-"){
                    st.push(a-b);
                }
                else if(ch=="*"){
                    st.push(a*b);
                }
                else{
                    st.push(a/b);
                }
            }
        }

        return st.top();
    }
};