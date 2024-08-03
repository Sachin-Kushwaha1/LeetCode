class Solution {
public:
    int lcs(string& s1, string& s2, int n, int m, vector<vector<int>>&dp)
    {
        if(m<0 || n<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n]==s2[m]) return dp[n][m] = 1+lcs(s1,s2,n-1,m-1,dp);
        return dp[n][m] = max(lcs(s1,s2,n-1,m,dp),lcs(s1,s2,n,m-1,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return lcs(s1,s2,n-1,m-1,dp);
    }
};
