class Solution {
public:
    string intToRoman(int num) {
        vector<int>temp={
            1000,900,500,400,
            100,90,50,40,10,9,
            5,4,1
        };
        vector<string>val={
            "M","CM","D","CD",
            "C","XC","L","XL",
            "X","IX","V","IV","I"
        };
        string result="";
        for(int i=0;i<temp.size();i++){
            while(num >=temp[i]){
                result+=val[i];
                num-=temp[i];
            }
        }
        return result;
        
    }
};