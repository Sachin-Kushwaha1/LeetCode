class Solution {
public:
    vector<int> help(vector<int>& v1, vector<int>& v2)
    {
        vector<int> ans;
        int j=0;
        for(int i=0;i<v2.size() && j<v1.size();i++)
        {
            while(v2[i] > v1[j] && j<v1.size()) {
                ++j;
                if(j>=v1.size()) break;
            }
            if(j>=v1.size()) break;
            if(v1[j] == v2[i]) {
                ans.push_back(v1[j]); 
                ++j;
            }
        }
        return ans;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        if(nums1.size()>nums2.size()) return help(nums2,nums1);
        return help(nums1,nums2);
    }
};