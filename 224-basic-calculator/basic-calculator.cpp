class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        long long number=0;
        long long result=0;
        int sign=1;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                continue;
            }
            else if(isdigit(s[i])){
                number=number*10+(s[i]-'0');
            }
            else if(s[i]=='+'){
                result+=(number*sign);
                number=0;
                sign=1;
            }
            else if(s[i]=='-'){
                result+=(number*sign);
                number=0;
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
            }
            else if(s[i]==')'){
                result+=number*sign;
                number=0;

                int st_sign=st.top();
                st.pop();
                int st_val=st.top();
                st.pop();

                result=result*st_sign;
                result+=st_val;
            }
        }
        result+=(number*sign);
        return result;
    }
};