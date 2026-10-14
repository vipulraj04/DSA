class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if(sum > num*9){
            return "";
        }
        int nines=sum/9;
        int remain=sum%9;
        StringBuilder res=new StringBuilder();
        for(int i=0;i<nines;i++){
            res.append('9');
        }
        if(remain > 0){
            res.append(remain);
        }
        while(res.length() < num){
            res.append('0');
        }
        return res.toString();
    }
}