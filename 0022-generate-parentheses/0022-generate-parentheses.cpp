class Solution {
public:
    void help(int n, int lc, int rc, vector<char>&op, vector<string>& res)
    {
        if(lc >= n && rc >= n)
        {
            string op1(op.begin(), op.end());
            res.push_back(op1);
            return;
        }
        if(lc<n)
        {
            op.push_back('(');
            help(n, lc+1, rc, op, res);
            op.pop_back();
        }
        if(rc<lc)
        {
            op.push_back(')');
            help(n, lc, rc+1, op, res);
            op.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        int rc=0,lc=0;
        vector<char>op;
        vector<string>res;
        help(n, lc, rc, op, res);
        return res;
    }
};