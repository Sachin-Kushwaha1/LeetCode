#define ll long long
class Solution {
public:
    ll dp[26][26];
    ll func(int src,int dst,vector<pair<ll,ll>>adj[]){
        if(dp[src][dst]!=-1) return dp[src][dst];
        set<pair<ll,ll>>st;
        vector<ll>dist(26,1e9);
        st.insert({0,src});
        dist[src]=0;
        while(!st.empty()){
            auto it=*(st.begin());
            ll node=it.second;
            ll dis=it.first;
            st.erase(it);
            if(node==dst) return dp[src][dst]=dis;
            for(auto it:adj[node]){
                ll adjNode=it.second;
                ll edW=it.first;
                if(dis+edW<dist[adjNode]){
                    if(dist[adjNode]!=1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode]=dis+edW;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return -1;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<pair<ll,ll>>adj[26];
        ll ans=0;
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<original.size();++i){
            adj[original[i]-'a'].push_back({cost[i],changed[i]-'a'});
        }
        // cout<<shortestDistance(3,4,adj)<<endl;
        for(int i=0;i<source.size();++i){
            ll temp=func(source[i]-'a',target[i]-'a',adj);
            if(temp==-1) return temp;
            ans+=temp;
        }
        return ans;
    }
};