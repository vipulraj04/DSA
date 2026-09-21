class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character>st=new HashSet<>();
        int n=s.length();
        int maxLength=0;
        int left=0;
        for(int right=0;right<n;right++){
            int length=0;
            Character ch=s.charAt(right);
            while(st.contains(ch)){
                st.remove(s.charAt(left));
                left++;
            }

            st.add(s.charAt(right));
            maxLength=Math.max(maxLength,right-left+1);
        }
        return maxLength;
    }
}