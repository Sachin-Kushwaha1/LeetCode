class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        vector<int>v1=arr1;
        for(int i=0;i<arr2.size();i++)
            for(int j=0;j<arr1.size();j++)
                if(arr2[i]==arr1[j]) 
                {
                    v1[j]=-1;
                    ans.push_back(arr1[j]);
                }
        sort(v1.begin(),v1.end());
        for(auto it1:v1)
            if(it1!=-1) ans.push_back(it1);
            
        return ans;
    }
};