class Solution {
public:
    void cnt(int n, vector<int>arr,int i, int sum, int& cs,vector<int>&v, vector<vector<int>>& ans)
	{
	    if(cs>sum) return;
        if(i>=n)
	    {
	        if(cs==sum) ans.push_back(v);
	        return;
	    }
	    
	    cs += arr[i];
        v.push_back(arr[i]);
	    cnt(n,arr,i,sum,cs,v,ans);
        v.pop_back();
	    
	    cs -= arr[i];
        cnt(n,arr,i+1,sum,cs,v,ans); 
	}
    vector<vector<int>> combinationSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<int>> ans;
        vector<int>v;
        int cs=0;
        cnt(n,arr,0,sum,cs,v,ans);
        return ans;
    }
};