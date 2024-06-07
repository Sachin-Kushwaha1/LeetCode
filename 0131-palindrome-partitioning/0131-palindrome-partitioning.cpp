class Solution {
public:
    bool isPalindrome(string S,int i, int j)
    {
        while(i<=j)
            if (S[i++] != S[j--]) 
                return false;
        return true;
    }
    void part(string s, int n, int ind,vector<string>&v, vector<vector<string>>&ans)
    {
        if(ind>=n)
        {
            ans.push_back(v);
            return;
        }

        for(int i=ind;i<n;i++)
        {
            if(isPalindrome(s,ind,i))
            {
                v.push_back(s.substr(ind, i - ind + 1));
                part(s,n,i+1,v,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        part(s,s.length(),0,v,ans);
        return ans;
    }
};