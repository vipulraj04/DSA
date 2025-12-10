class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=players.size();
        int m=trainers.size();
        int i=0;
        int j=0;
        int count=0;

        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        while(i<n && j<m){
            if(players[i]<=trainers[j]){
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return count;
        
    }
};