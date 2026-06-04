class Solution {
public:
void helper(int i,int &count){
    int prev=i%10;
    i=i/10;
    
    int mid=i%10;
    i=i/10;

    while(i){
        int next=i%10;

        if((mid < prev ) && (mid < next) ||
        (mid > prev) &&  (mid> next)){
            count++;
        }

        prev=mid;
        mid=next;
        i=i/10;
    }
}
    int totalWaviness(int num1, int num2) {
        int count=0;
        for(int i=num1;i<=num2;i++){
            helper(i,count);
        }
        return count;
    }
};