class Solution {
public:
bool isVowel(char ch){
    return ch=='a' || ch=='e' || ch=='i'|| ch=='o' || ch=='u';
}
long long helper(string word,int k){
    long long result=0;
    unordered_map<char,int>mp;
    int i=0;
    int j=0;
    int n=word.length();
    int cot=0;
    while(j< n){
        char ch=word[j];
        if(isVowel(ch)){
            mp[ch]++;
        }
        else{
            cot++;
        }

        while(mp.size()==5 && cot >=k){
            result+=n-j;
            char c=word[i];
            if(isVowel(c)){
                mp[word[i]]--;
                if(mp[word[i]]==0){
                    mp.erase(word[i]);
                }
            }
            else{
                cot--;
            }
            i++;
        }
        j++;
    }
    return result;
}
    long long countOfSubstrings(string word, int k) {
        return helper(word,k) - helper(word,k+1);
    }
};