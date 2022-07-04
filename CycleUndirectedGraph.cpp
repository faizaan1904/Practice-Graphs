bool isCycle(int V, vector<int> adj[]) {
        queue<pair<int,int>> q;
        vector<bool> vis(V,0);
        for(int i = 0; i < V; i++){
            if(vis[i]) continue;
            
            q.push({i,-1});
            vis[i] = true;
            while(!q.empty()){
                int u = q.front().first;
                int par = q.front().second;
                q.pop();
                for(auto v: adj[u]){
                    if(vis[v] == true and v != par) 
                    	return 1;
                    if(vis[v]) 
                    	continue;
                    q.push({v,u});
                    vis[v] = true;
                }
            }
        }
        
        return 0;
    }
