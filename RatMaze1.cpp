#define MAX 5
class Solution{
    public:
     void getallpath(vector<vector<int>> matrix, int n,int row,int col,vector<string> &ans,string cur)
    {
        if(row>=n or col>=n or row<0 or col<0 or matrix[row][col] == 0)
        return ;
        
        if(row == n-1 and col == n-1)
        {
            ans.push_back(cur);
            return ;
        }
        
        //now if its one we have 4 calls
        matrix[row][col] = 0;
        
        getallpath(matrix,n,row-1,col,ans,cur+"U");
        getallpath(matrix,n,row,col+1,ans,cur+"R");
        getallpath(matrix,n,row,col-1,ans,cur+"L");
        getallpath(matrix,n,row+1,col,ans,cur+"D");
        
        matrix[row][col] = 1;
        
        return ;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        getallpath(m,n,0,0,ans,"");
        return ans;
    }
};
