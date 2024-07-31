class Solution {
public:
    int help(int i, vector<vector<int>>a, int w, vector<int>&dp,int n)
    {
        if (i>=n)
         return 0;
        if(dp[i]!=INT_MAX)
         return dp[i];
        int cw=0,ch=0;
        for(int j=i;j<n;j++)
        {
           if(cw+a[j][0]<=w)
            {
                dp[i]=min(dp[i],max(ch,a[j][1])+help(j+1,a,w,dp,n));
                ch=max(ch,a[j][1]);
                cw+=a[j][0];
            }
            else
             break;
           
        }
        return dp[i];

    }
    int minHeightShelves(vector<vector<int>>& books, int sw) {
        int n=books.size();
        vector<int>dp(n,INT_MAX);
        return help(0,books,sw,dp,n);
    }
};