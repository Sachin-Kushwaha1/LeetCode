class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int totalone = accumulate(nums.begin(),nums.end(),0);
        if(totalone == n) return 0;
        int j=0;
        int c1=accumulate(nums.begin(),nums.begin()+totalone,0);;
        int ans = totalone - c1;
        for(int i=0; i<n ; i++)
        {
            c1 += nums[(i+totalone)%n]-nums[i];
            ans = min(totalone-c1,ans);
        }
        return ans;
    }
};