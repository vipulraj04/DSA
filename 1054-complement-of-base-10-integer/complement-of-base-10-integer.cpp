class Solution {
public:
    int bitwiseComplement(int n) {
        string s=bitset<32>(n).to_string();
        if(n==0){
            return 1;
        }

        int num=floor(log2(n))+1;

        string result="";
        for(int i=32-num;i<32;i++){
            if(s[i]=='0'){
                result+='1';
            }
            else{
                result+='0';
            }
        }
        int ans=stoi(result,nullptr,2);

        return ans;
    }
};