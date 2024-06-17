class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        int n=sqrt(c);

        for(int i=0;i<=n;i++)
        {
            double b=sqrt(c-i*i);
            if(b==(int)b)
            return true;
        }
       

        
        return false;
        
    }
};