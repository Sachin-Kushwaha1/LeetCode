class Solution {
public:

    bool judgeSquareSum(int c) {
        for(double i=0;i*i<=c;i++)
        {
            double x = c - i*i;
            if(floor(sqrt(x)) == ceil(sqrt(x)))
                return true;
        }
        return false;
    }
};