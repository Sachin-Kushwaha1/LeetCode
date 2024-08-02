class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int totalone = accumulate(nums.begin(),nums.end(),0);
        if(totalone == n) return 0;
        int j=0;
        int c1=0;
        for(int i=0;i<totalone;i++)
            if(nums[i]) ++c1;
        int ans = totalone - c1;
        for(int i=0, j=totalone; j<n && i<n ; i++, j = (j+1)%n)
        {
            c1 += nums[j]-nums[i];
            ans = min(totalone-c1,ans);
        }
        return ans;
    }
};