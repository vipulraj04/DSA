class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total=0;

        for(int num : nums){
            total+=countDivisor(num);
        }
        return total;
    }

    int countDivisor(int num){
        int divisor=0;
        int sum=0;

        for(int i=1;i*i<=num;i++){
            if(num%i==0){
                int other=num/i;

                if(i==other){
                    divisor+=1;
                    sum+=i;
                }
                else{
                    divisor+=2;
                    sum+=(i+other);
                }
            }
            if(divisor > 4)
            return 0;
        }

        if(divisor==4){
            return sum;
        }
        
        return 0;
    }
};