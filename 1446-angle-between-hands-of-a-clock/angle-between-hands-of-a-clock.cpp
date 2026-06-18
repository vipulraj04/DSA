class Solution {
public:
    double angleClock(int hour, int minutes) {
        double result=abs((5.5*minutes) - (30*hour));

        if(result>180){
            return 360-result;
        }
        return result;
    }
};