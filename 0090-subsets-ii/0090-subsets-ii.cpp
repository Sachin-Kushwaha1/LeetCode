class Solution {
public:
    void subseq(vector<int> &v, int n, int i,vector<int>&c ,vector<vector<int>> &ans) 
    {
        if (i >= n) {
            ans.push_back(c); 
            return;
        }
        c.push_back(v[i]);
        subseq(v, n, i + 1, c, ans);
        c.pop_back();
        subseq(v, n, i + 1, c, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        vector<int> c;
        subseq(v, v.size(), 0, c, ans);
        set<vector<int>>st;
        for(auto it:ans)
         st.insert(it);
        ans.clear();
        for(auto it:st)
            ans.push_back(it); 
        return ans;
    }
};