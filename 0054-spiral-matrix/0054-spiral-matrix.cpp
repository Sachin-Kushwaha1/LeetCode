class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        if(n==1) return mat[0];
        int m=mat[0].size();
        int c=0;
        vector<vector<int>>v(n, vector<int>(m,0));
        vector<int>ans;
        if(m==1){
            for(auto it:mat)
                ans.push_back(it[0]);
            return ans;
        }
        int i=0,j=0;
        while(c<n*m)
        {
            while(j<m and v[i][j]==0)
            {
                ++c;
                v[i][j]=1;
                ans.push_back(mat[i][j]);
                ++j;
                if(j>=m || v[i][j])
                {
                    --j;
                    ++i;
                    break;
                }
            }
            while(i<n and v[i][j]==0)
            {
                ++c;
                v[i][j]=1;
                ans.push_back(mat[i][j]);
                ++i;
                if(i>=n || v[i][j])
                {
                    --i;
                    --j;
                    break;
                }
            }
            while(j>=0 and v[i][j]==0)
            {
                ++c;
                v[i][j]=1;
                ans.push_back(mat[i][j]);
                --j;
                if(j<0 || v[i][j])
                {
                    ++j;
                    --i;
                    break;
                }
            }
            while(i>=0 and v[i][j]==0)
            {
                ++c;
                v[i][j]=1;
                ans.push_back(mat[i][j]);
                --i;
                if(i<0 || v[i][j])
                {
                    ++i;
                    ++j;
                    break;
                }
            }
        }
        return ans;
    }
};