class Solution {
public:
    int help(vector<int>nums, int i, vector<int>&dp)
    {
        if(i==0) return nums[i];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + help(nums,i-2,dp);
        int notake = 0 + help(nums,i-1,dp);
        return dp[i] = max(take,notake);
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>v1(nums.begin(),nums.end()-1);
        vector<int>v2(nums.begin()+1,nums.end());
        vector<int>dp1(n-1,-1);
        vector<int>dp2(n-1,-1);
        int ans1 = help(v1,n-2,dp1);
        int ans2 = help(v2,n-2,dp2);
        return max(ans1,ans2);
    }
};