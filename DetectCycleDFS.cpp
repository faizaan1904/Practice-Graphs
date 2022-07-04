    /*bool DFSrec(vector<int> adj[],int s, vector<bool> vis,vector<bool> revis){
        vis[s]=true;
        revis[s]=true;
        for(auto it: adj[s]){
            if(vis[it]==false&&DFSrec(adj,it,vis,revis)){
                return true;
            }
            else if(revis[it]==true)
                return true;
            
        }
        revis[s]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,false);
        vector<bool> revis(V,false);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                if(DFSrec(adj,i,vis,revis)==true)
                    return true;
            }
        }
        return false;
    }*/
    bool iscyclicdfs(int i,unordered_map<int,bool>&vis,unordered_map<int,bool>&dfsvis,  vector<int>adj[]){
       vis[i]=true;
       dfsvis[i]=true;
       
       for( auto neighbour:adj[i]){
           if(!vis[neighbour]){
                bool checkcycle=iscyclicdfs(neighbour,vis,dfsvis,adj);
               if(checkcycle)
               return true;
           }
           
           else if(dfsvis[neighbour]){
              return true;
           }
    
       }
       dfsvis[i]=false;
       return false;
   }
   bool isCyclic(int V, vector<int> adj[]) {
       
      
      unordered_map<int,bool>vis;
        unordered_map<int,bool>dfsvis;
       for(int i=0;i<V;i++){
           if(!vis[i]){
               bool checkcycle=iscyclicdfs(i,vis,dfsvis,adj);
               if(checkcycle)
               return true;
           }
       }
  return false; }
