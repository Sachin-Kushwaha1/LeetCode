class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int,int>m;
        // vector<int>ans;
        for(int i=0;i<matrix.size();i++)
        {
            int mn=INT_MAX;
            for(int j=0;j<matrix[0].size();j++)
                mn = min(mn,matrix[i][j]);
            ++m[mn];
        }
        for(int i=0;i<matrix[0].size();i++)
        {
            int mx=0;
            for(int j=0;j<matrix.size();j++)
                mx = max(mx,matrix[j][i]);
            ++m[mx];
        }
        int t=0;
        int ans=0;
        for(auto it:m)
            if(it.second>t && it.second!=1) {
                t = it.second;
                ans = it.first;
            }
        if(ans==0) return{};
        return {ans};
    }
};