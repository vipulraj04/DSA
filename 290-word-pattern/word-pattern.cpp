class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>temp;
        string result="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                temp.push_back(result);
                result="";
            }
            else{
                result+=s[i];
            }
        }
        temp.push_back(result);
        if(temp.size()!=pattern.length()){
            return false;
        }
        unordered_map<string,char>mp;
        set<char>st;
        for(int i=0;i<pattern.length();i++){
            char ch=pattern[i];
            string word=temp[i];

            if(mp.find(word)==mp.end() && st.find(ch)==st.end()){
                mp[word]=ch;
                st.insert(ch);
            }
            else if(mp[word]!=pattern[i]){
                return false;
            }
        }
        return true;
    }
};