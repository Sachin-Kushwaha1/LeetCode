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
        cnt(n,arr,i+1,sum,cs,v,ans);
        v.pop_back();
	    cs -= arr[i];
        int j=i;
        while(j<arr.size() && arr[i]==arr[j]){
            j++;
        }
        cnt(n,arr,j,sum,cs,v,ans); 
	}
    vector<vector<int>> combinationSum2(vector<int>& arr, int sum) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int>v;
        int cs=0;
        cnt(n,arr,0,sum,cs,v,ans);
        // set<vector<int>>st(ans.begin(),ans.end());
        // ans.clear();
        // for(auto it:st)
        // {
        //     ans.push_back(it);
        // }
        return ans;
    }
};