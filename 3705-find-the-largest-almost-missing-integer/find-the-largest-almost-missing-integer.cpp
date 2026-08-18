class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        map<int ,int>mainMap;
        map<int,int>wMap;
        int left=0;
        for(int right=0;right<n;right++){
            wMap[nums[right]]++;

            if(right-left+1 ==k){
                for(auto & it:wMap){
                    mainMap[it.first]++;
                }

                wMap[nums[left]]--;

                if(wMap[nums[left]]==0){
                    wMap.erase(nums[left]);
                }
                left++;
            }
        }
        int result=-1;
        for(auto & it:mainMap){
            if(it.second==1){
                result=max(result,it.first);
            }
        }
        return result;
    }
};