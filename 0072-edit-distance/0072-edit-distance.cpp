class Solution {
  public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
        int n = s1.size();
        int m = s2.size();
        if(i>=n) return m-j;
        if(j>=m) return n-i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take = 0;
        int notTake = 0;
        if(s1[i]==s2[j]){
            take = solve(i+1,j+1,s1,s2,dp);
        }else{
            int insertOp = 1 + solve(i,j+1,s1,s2,dp);
            int deleteOp = 1 + solve(i+1,j,s1,s2,dp);
            int replaceOp = 1 + solve(i+1,j+1,s1,s2,dp);
            
            notTake = min(insertOp,min(deleteOp,replaceOp));
        }
        
        return dp[i][j] = take + notTake;
    }
    int minDistance(string s1, string s2) {
        // Code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        int x = solve(0, 0, s1, s2, dp);
        return x;
    }
};