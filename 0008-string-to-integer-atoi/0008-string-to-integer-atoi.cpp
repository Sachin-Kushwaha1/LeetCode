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
            cout<<x<<endl;
            ++i;
            if(x>2147483647) break;
        }       
        if(ne == '-')
            x*=(-1);
        if(x>2147483647) return 2147483647;
        if(x<-2147483648) return -2147483648;
        
        return x;
    }
};