class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            int sl=0,bl=0,sr=0,br=0;
            for(int j=0;j<i;j++)
            {
                if(rating[j]<rating[i])
                    ++sl;
                else ++bl; 
            }
            for(int k=i+1;k<n;k++)
            {
                if(rating[k]>rating[i]) ++br;
                else ++sr;
            }
            ans += sl*br + bl*sr;
        }
        return ans;
    }
};