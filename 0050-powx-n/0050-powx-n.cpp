class Solution {
public:
    void help(double& x, double& n1, double& ans)
    {
        if(n1==0) return;
        if(fmod(n1,2))
        {
            --n1;
            ans = ans*x;
        }
        else 
        {
            n1/=2;
            x = x*x;
        }
        help(x,n1,ans);
    }
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==1) return 1;
        double ans=1;
        double nn=n;
        if(n<0)
        {
            nn *= -1;
            help(x,nn,ans);
            return 1/ans;
        }
        help(x,nn,ans);
        return ans;
    }
};