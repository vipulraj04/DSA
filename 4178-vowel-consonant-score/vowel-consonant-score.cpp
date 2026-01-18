class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowel=0;
        int con=0;
        for(char ch: s){
            if(ch>='a' && ch<='z'){
                if(isVowel(ch)){
                    vowel++;
                }
                else{
                    con++;
                }
            }
        }
        if(con==0){
            return 0;
        }

        return (vowel/con);
    }
    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
};