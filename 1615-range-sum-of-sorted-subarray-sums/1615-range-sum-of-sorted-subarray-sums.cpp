class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int s = 0;
            for(int j=i;j<n;j++)
            {
                s += nums[j];
                v.push_back(s);
            }
        }
        sort(v.begin(),v.end());
        int mod = (1e9+7);
        int ans=0;
        for(int i=left-1;i<right;i++)
            ans = (ans + v[i]) % mod;
        return ans; 
    }
};