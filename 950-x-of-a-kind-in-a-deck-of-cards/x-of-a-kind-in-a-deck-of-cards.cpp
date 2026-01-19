class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>result;

        for(int it:deck){
            result[it]++;
        }

        int g=0;
        for (auto &p : result){
            g=gcd(g,p.second);
        }

        return g>=2;
    }
};