class Solution {
public:
    // int solve(int n, vector<int>&dp)
    // {
    //     if(n<=2)
    //     {
    //         dp[n]=n;
    //         return dp[n];
    //     }
    //     if(dp[n]!=-1)
    //         return dp[n];
    //     return dp[n] = solve(n-2,dp) + solve(n-1,dp);
    // }
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
        // solve(n,dp);
        // return dp[n];
        int s=0,s1=1;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans = s+s1;
            s=s1;
            s1=ans;
        }
        return ans;
    }
};