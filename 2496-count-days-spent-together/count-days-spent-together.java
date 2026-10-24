class Solution {
    public int helper(String s){
        int month=Integer.parseInt(s.substring(0,2));
        int days=Integer.parseInt(s.substring(3));

        int [] daysMonths={31,28,31,30,31,30,31,31,30,31,30,31};

        for(int i=0;i<month-1;i++){
            days+=daysMonths[i];
        }
        return days;
    }
    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int aliceA=helper(arriveAlice);
        int bobA=helper(arriveBob);
        int aliceE=helper(leaveAlice);
        int bobE=helper(leaveBob);

        int left=Math.max(aliceA,bobA);
        int right=Math.min(aliceE,bobE);

        int ans=right-left+1;

        return Math.max(0,ans);
    }
}