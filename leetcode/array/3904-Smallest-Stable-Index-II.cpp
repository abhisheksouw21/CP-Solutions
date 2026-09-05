class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>v(n);
         v[n-1]=nums[n-1];
         for(int i=n-2;i>=0;--i){
            v[i]=min(nums[i],v[i+1]);
         }
         int mx=nums[0];
         for(int i=0;i<n;++i){
            mx=max(nums[i],mx);
            if(mx-v[i]<=k){
                return i;
            }
         }
         return -1;
    }
};