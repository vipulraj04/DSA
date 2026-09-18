class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];

            if(st.empty()){
                st.push(ch);
            }
            else if(st.top()==ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        string result="";
        while(!st.empty()){
            char ch=st.top();
            result+=ch;
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};