class Solution {
public:
    string addBinary(string a, string b) {
        int lenA=a.length();
        int lenB=b.length();
        int i=lenA-1;
        int j=lenB-1;
        int carry=0;
        string result="";

        while(i>=0 || j>=0 || carry ){
            int sum=carry;
            if(i>=0){
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }

            result.push_back((sum%2)+'0');
            carry=sum/2;
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};