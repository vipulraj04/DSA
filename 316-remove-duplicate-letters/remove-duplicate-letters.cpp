class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        string result="";
        vector<int>lastSeen(26);
        vector<int>taken(26,false);
        for(int i=0;i<n;i++){
            char ch=s[i]-'a';
            lastSeen[ch]=i;
        }

        for(int i=0;i<n;i++){
            char ch=s[i];
            if(taken[ch-'a']==true){
                continue;
            }
            while(!result.empty() && result.back()> ch && lastSeen[result.back()-'a']>i){
                taken[result.back()-'a']=false;
                result.pop_back();
            }
            taken[ch-'a']=true;
            result+=ch;
        }
        return result;
    }
};