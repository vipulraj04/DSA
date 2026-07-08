class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>>result(256);
        for(char &ch : s){
            int freq=result[ch].second;
            result[ch]={ch,freq+1};
        }
        auto lambda=[](pair<char,int>&p1,pair<char,int>&p2){
            return p1.second > p2.second;
        };

        sort(result.begin(),result.end(),lambda);

        string ans="";
        for(auto & it: result){
            char ch=it.first;
            int freq=it.second;
            if(freq==0){
                continue;
            }
            //string temp=string()
            ans+=string(freq,ch);
        }
        return ans;
    }
};