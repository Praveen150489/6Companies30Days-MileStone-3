// Unit Area of largest region of 1's .

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==false){
                    int count=0;
                    solve(i,j,grid,vis,count,n,m);
                    ans=max(ans,count);
                }
            }
        }
        return ans;
    }
    void solve(int x,int y,vector<vector<int>>& grid,vector<vector<bool>>& vis,int& count,int n,int m){
        vis[x][y]=true;
        count++;
        if(x-1>=0 && grid[x-1][y]==1 && vis[x-1][y]==false){
            solve(x-1,y,grid,vis,count,n,m);
        }
        if(x+1<n && grid[x+1][y]==1 && vis[x+1][y]==false){
            solve(x+1,y,grid,vis,count,n,m);
        }
        if(y-1>=0 && grid[x][y-1]==1 && vis[x][y-1]==false){
            solve(x,y-1,grid,vis,count,n,m);
        }
        if(y+1<m && grid[x][y+1]==1 && vis[x][y+1]==false){
            solve(x,y+1,grid,vis,count,n,m);
        }
        if(x-1>=0 && y-1>=0 && grid[x-1][y-1]==1 && vis[x-1][y-1]==false){
            solve(x-1,y-1,grid,vis,count,n,m);
        }
        if(x-1>=0 && y+1<m && grid[x-1][y+1]==1 && vis[x-1][y+1]==false){
            solve(x-1,y+1,grid,vis,count,n,m);
        }
        if(x+1<n && y-1>=0 && grid[x+1][y-1]==1 && vis[x+1][y-1]==false){
            solve(x+1,y-1,grid,vis,count,n,m);
        }
        if(x+1<n && y+1<m && grid[x+1][y+1]==1 && vis[x+1][y+1]==false){
            solve(x+1,y+1,grid,vis,count,n,m);
        }
    }
};
