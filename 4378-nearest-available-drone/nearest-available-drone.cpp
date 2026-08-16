class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int xj=target[0];
        int yj=target[1];
        int result=-1;
        int minDist=INT_MAX;

        for(int i=0;i<drones.size();i++){
            int xi=drones[i][0];
            int yi=drones[i][1];
            int range=drones[i][2];

            int dist=abs(xi-xj) + abs(yi-yj);
            if(dist > range){
                continue;
            }

            if(minDist > dist){
                result=i;
                minDist=dist;
            }
        }

        return result;
    }
};