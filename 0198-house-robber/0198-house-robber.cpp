class Solution {
public:
    int help(vector<int>nums, int i, vector<int>&dp, int n)
    {
        
        if(i==0)    return nums[i];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int l = nums[i] + help(nums,i-2,dp,n);
        int r = 0 + help(nums,i-1,dp,n);
        return dp[i] = max(l,r);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return help(nums,n-1,dp,n);
    }
};