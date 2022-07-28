class Solution {
public:
    void f(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j,int m,int n){
        if(i<0||i>m-1||j<0||j>n-1||grid[i][j]=='0'||visited[i][j]) return;
        visited[i][j]=true;
        f(grid,visited,i,j+1,m,n);
        f(grid,visited,i+1,j,m,n);
        f(grid,visited,i,j-1,m,n);
        f(grid,visited,i-1,j,m,n);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int c=0,m=grid.size(),n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
       
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    c++;
                    f(grid,visited,i,j,m,n);
                }
            }
        }
        return c;
    }
};
