class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        string ans="";
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(digits,result,ans,mapping,index);
        return result;
    }

    void helper(string digits,vector<string>&result,string ans,string mapping[],int index){
        if(index==digits.length()){
            result.push_back(ans);
            return;
        }

        int number=digits[index]-'0';
        string value=mapping[number];
        for(int i=0;i<value.length();i++){
            ans.push_back(value[i]);
            helper(digits,result,ans,mapping,index+1);
            ans.pop_back();
        }
    }
};