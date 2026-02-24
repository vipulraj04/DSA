class Solution {
public:
int getDigit(int n){
    int last=0;
    while(n>0){
        int rem=n%10;
        last += rem*rem;
        n=n/10;
    }
    return last;
}
    bool isHappy(int n) {
        unordered_set<int>st;
        while(n!=1){
            if(st.find(n)==st.end()){
                st.insert(n);
                n=getDigit(n);
            }
            else{
                return false;
            }
        }
        return true;
    }
};