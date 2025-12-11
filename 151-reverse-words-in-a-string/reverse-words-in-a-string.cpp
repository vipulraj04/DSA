class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string word;

        string temp="";
        for(int i=0; s[i]!='\0'; i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else if(s[i]==' ' && !temp.empty()){
                reverse(temp.begin(),temp.end());

                word.push_back(' ');
                
                word+=temp;
                temp="";

            }



        }

        if(!temp.empty()){

        
        word.push_back(' ');
        reverse(temp.begin(),temp.end());
        word+=temp;
        
        }
        return word.substr(1,word.length());
    }
};