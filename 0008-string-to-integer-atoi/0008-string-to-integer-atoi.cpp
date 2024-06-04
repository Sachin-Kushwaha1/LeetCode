class Solution {
public:
    int myAtoi(string s) {
        deque<char>s1;
        for(auto it:s)
            s1.push_back(it);
        while(s1.front() == ' ') s1.pop_front();
        int i=0;
        char sig;
        if(s1.front() == '-' || s1.front() == '+')
        {
            sig = s1.front();
            s1.pop_front();
        }
        while( s1.front() == '0') s1.pop_front();
        string s2="";
        while(!s1.empty())
        {
            s2 += s1.front();
            s1.pop_front();
        }
        cout<<s2<<endl;
        long x=0;
        i=0;
        while( s2[i] >= '0' && s2[i] <= '9')
        {
            cout<<s2[i] -'0'<<endl;
            x = 10*x + s2[i]-'0';
            ++i;
            if(x>INT_MAX) break;
        }       
        if(sig == '-')
            x *= -1;
        if(x>INT_MAX) return INT_MAX;
        if(x<INT_MIN) return INT_MIN;
        
        return x;
    }
};