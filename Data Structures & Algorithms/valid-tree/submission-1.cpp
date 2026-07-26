class Solution {
public:
    bool check(int node,int par,vector<int>& vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(check(it,node,vis,adj)) return true;
            }
            else if(it!=par) return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1){
            return false;
        }
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) if(check(i,-1,vis,adj)) return false;
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }
        return true;
    }
};
