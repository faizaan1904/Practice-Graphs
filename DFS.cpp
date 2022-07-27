void dfs(int v, vector<vector<int>> adj, vector<int>& ans, vector<bool>& vis){
        
        vis[v] = true;
        ans.push_back(v);
        
        for(auto child : adj[v]){
            if(vis[child]==false)    
                dfs(child, adj, ans, vis);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V, false);
        
        dfs(0, adj, ans, vis);
        
        return ans;
    }
