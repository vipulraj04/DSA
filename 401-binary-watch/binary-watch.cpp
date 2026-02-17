class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>result;
        for(int h=0;h<=11;h++){
            for(int m=0;m<=59;m++){
                if(__builtin_popcount(h)+__builtin_popcount(m)==turnedOn){
                    string hours=to_string(h);
                    string min;
                    if(m<10){
                        min="0"+to_string(m);
                    }
                    else{
                        min=to_string(m);
                    }
                    result.push_back(hours + ":" + min);
                }
            }
        }

        return result;
        
    }
};