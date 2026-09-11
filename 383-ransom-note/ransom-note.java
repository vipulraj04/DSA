class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int n=magazine.length();
        int[] freq=new int[26];
        for(int i=0;i<n;i++){
            char ch=magazine.charAt(i);
            int c=ch-'a';

            freq[c]++;
        }

        for(int i=0;i<ransomNote.length();i++){
            char ch=ransomNote.charAt(i);
            int c=ch-'a';
            if(freq[c]==0){
                return false;
            }
            freq[c]--;
        }

        return true;
    }
}