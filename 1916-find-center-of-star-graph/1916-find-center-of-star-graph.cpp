class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>m;
        for(auto it:edges)
        {
            ++m[it[0]];
            ++m[it[1]];
        }
        int ans=0,max=0;
        for(auto it:m)
            if(it.second>max)
            {
                max=it.second;
                ans=it.first;
            }
        return ans;
    }
};