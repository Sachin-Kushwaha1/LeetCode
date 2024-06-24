class Solution {
public:
    int minKBitFlips(vector<int>& v, int k) {
        // int n=nums.size();
        // int st=0,e=0;
        // int s=accumulate(v.begin(),v.end(),0);
        // if(s==n) return 0;
        // if( n-s <k) return -1;
        // int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     while(v[i]) ++i;
        //     if(v[i]==0)
        //     {
        //         if(i>=en)
        //         {
        //             ++ans;
        //             st=i;
        //             en=i+k;
        //             if(en>n) return -1;
        //             if(en==n) return ans;
        //         }
        //     }
        //     else
        //     {
        //         if(i>en)
        //         {
        //             ++ans;
        //             st=i;
        //             en=i+k;
        //             if(en>=n) return -1;
        //             if(en==n) return ans;
        //         }
        //     }
        // }
        int ans=0,x,n=v.size();
        vector<int> m(n,0);
        for(int i=0;i<n;i++)
        {
            x=0;
            if((i-1)>=0){ x=m[i-1];
            if((i-k)>=0) x=x-m[i-k];}

            if(((x%2)^v[i])==0 )
            {
                if(i>n-k) return -1;
                m[i]=1;
                ans++;
            }
            if(i>0)
            m[i]+=m[i-1];
        }
        return ans;
    }
};