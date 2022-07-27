 /* struct rc{   int r; int c; };
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig_color = image[sr][sc];
        if(color == orig_color) return image;
        int m = image.size(), n= image[0].size();
        
        vector<rc> dirs= { 
                rc{-1,0},
            rc{0,-1},   rc{0,+1},
                rc{+1,0}
        };
        queue<rc> Q; 
        image[sr][sc] = color;
        Q.push(rc{sr,sc});
        while(!Q.empty()) {
            rc e = Q.front();
            Q.pop();
            for(auto &d: dirs) {
                int r = e.r+d.r;
                int c = e.c+d.c;
                if(r<0 || r>=m || c<0 || c>=n) continue;
                if(image[r][c] == orig_color) {
                    image[r][c] = color;
                    Q.push(rc{r,c});    
                }
            }
        }
        return image;
    }
*/
class Solution {
public:
    void f(vector<vector<int>>& image, int r, int c, int &color,int &cc,int &m,int &n,vector<vector<bool>>& vis){
        if(r<0||r>m-1||c<0||c>n-1||image[r][c]!=cc||vis[r][c]){
            return;
        }
       vis[r][c]=true;
       image[r][c]=color;
        
        f(image,r-1,c,color,cc,m,n,vis);
        f(image,r,c-1,color,cc,m,n,vis);
        f(image,r+1,c,color,cc,m,n,vis);
        f(image,r,c+1,color,cc,m,n,vis);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int cc=image[sr][sc],m=image.size(),n=image[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        f(image,sr,sc,color,cc,m,n,vis);
        return image;
    }
};
