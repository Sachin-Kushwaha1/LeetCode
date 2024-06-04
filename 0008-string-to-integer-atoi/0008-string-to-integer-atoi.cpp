class Solution {
public:
    int myAtoi(string s) {
        long x=0;
        while(s[0] == ' ') s.erase(s.begin());
        int i=0;
        char ne;
        if(s[0]=='-' || s[0]=='+')
        {
            ne=s[0];
            s.erase(s.begin());
        }
        while(s[0] == '0') s.erase(s.begin());
        while(s[i] >= '0' && s[i] <= '9')
        {
            x = 10*x + s[i]-'0';
            ++i;
            if(x>INT_MAX) break;
        }       
        if(ne == '-')
            x*=(-1);
        if(x>INT_MAX) return INT_MAX;
        if(x< INT_MIN) return INT_MIN;
        
        return x;
    }
};