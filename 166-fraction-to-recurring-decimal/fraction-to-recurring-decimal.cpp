class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0){
            return "0";
        }

        string result="";

        if((numerator<0 && denominator>0)||(numerator>0 && denominator<0)){
            result+="-";
        }

        long long num=llabs(numerator);
        long long den=llabs(denominator);

        result+=to_string(num/den);
        long long res=num%den;

        if(res==0){
            return result;
        }

        result+=".";
        unordered_map<long long,int>mp;
        while(res!=0){
            if(mp.find(res)!=mp.end()){
                result.insert(mp[res],"(");
                result+=")";
                break;
            }
            mp[res]=result.size();
            res*=10;
            result+=to_string(res/den);
            res%=den;
        }
        return result;
    }
};