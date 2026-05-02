class Solution {
public:
bool isTrue(int num){
    bool found=false;
    while(num){
        int d=num%10;
        if(d==3 || d==4 || d==7){
            return false;
        }
        if(d==2 || d==5 || d==6 || d==9){
            found=true;
        }
        num=num/10;
    }
    return found;
}
    int rotatedDigits(int n) {
        int count=0;
        for(int i=1;i<=n;i++){
            if(isTrue(i)){
                count++;
            }
        }
        return count;
    }
};