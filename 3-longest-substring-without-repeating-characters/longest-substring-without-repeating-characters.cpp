class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      set<char>st;
      int n=s.length();
      int left=0;
      int maxLength=0;
      for(int right=0;right<n;right++){
        while(st.count(s[right])){
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);
        maxLength=max(maxLength,right-left+1);
      }  

      return maxLength;
    }
};