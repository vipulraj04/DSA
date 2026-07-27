class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int>mp;
        stack<int>st;
        reverse(nums2.begin(),nums2.end());
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top() <=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]]=-1;
            }
            else{
                mp[nums2[i]]=st.top();
            }

            st.push(nums2[i]);
        }
        vector<int>result;
        for(int x: nums1){
            result.push_back(mp[x]);
        }
        return result;
        
    }
};