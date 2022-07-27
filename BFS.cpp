vector<int> bfsOfGraph(int V, vector<vector<int>> adj) {
        // Code here
       bool travel[V+1];
       vector<int>v;
       queue<int>q;
       for(int i =0 ; i< V ; i++){
           travel[i]=false;
       }
       q.push(0);
       travel[0]=true;
       while(!q.empty()){
           int x=q.front();
           v.push_back(x);
           q.pop();
           for(auto i : adj[x]){
               if(travel[i]==false){
                   travel[i]=true;
                   q.push(i);
               }
           }
       }
       return v;
    }
