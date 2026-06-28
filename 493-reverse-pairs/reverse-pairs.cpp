class Solution {
public:
int merge(vector<int>&nums,int l,int h){
    int count=0;
    int mid=l+(h-l)/2;
    int j=mid+1;
    for(int i=l;i<=mid;i++){
        while(j<=h && (long long) nums[i]>2LL*nums[j]){
            j++;
        }
        count+=j-(mid+1);
    }
    vector<int>temp;
    int p1=l;
    int p2=mid+1;
    while(p1<=mid && p2<=h){
        if(nums[p1] < nums[p2]){
            temp.push_back(nums[p1]);
            p1++;
        }
        else{
            temp.push_back(nums[p2]);
            p2++;
        }
    }
    while(p1<=mid){
        temp.push_back(nums[p1++]);
    }
    while(p2<=h){
        temp.push_back(nums[p2++]);
    }
    for(int i=l;i<=h;i++){
        nums[i]=temp[i-l];
    }
    return count;
}

int mergeSort(vector<int>&nums,int l,int h){
    int count=0;
    if(l>=h){
        return 0;
    }
    int mid=l+(h-l)/2;
    count+=mergeSort(nums,l,mid);
    count+=mergeSort(nums,mid+1,h);
    count+=merge(nums,l,h);

    return count;
}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};