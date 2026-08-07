class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        while(!q.empty()){
            string str=q.front().first;
            int sr=q.front().second;
            q.pop();
            
            if(str==endWord){
                return sr;
            }
            for(int i=0;i<str.size();i++){
                char org=str[i];
                for(char ch='a';ch<='z';ch++){
                    str[i]=ch;

                    if(st.find(str)!=st.end()){
                        st.erase(str);
                        q.push({str,sr+1});
                    }
                }
                str[i]=org;
            }
        }
        return 0;
    }
};