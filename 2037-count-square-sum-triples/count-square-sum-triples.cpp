class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for(int a=1;a<n;a++){
            for(int b=a+1;b<n;b++){
                int squar=a*a+b*b;

                int c=sqrt(squar);


                if(c<=n && c*c==squar){
                    count+=2;
                }
            }
        }

        return count;
    }
};