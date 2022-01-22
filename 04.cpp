// Given a matrix of size r*c. Traverse the matrix in spiral form.

class Solution
{
    public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
    {
        // code here
        int n=matrix.size();
        int m=matrix[0].size();
        queue<int> q;
        int i=0;
        int j=0;
        int x=n-1;
        int y=m-1;
        while(i<x && j<y){
            for(int k=j;k<=y;k++){
                q.push(matrix[i][k]);
            }
            for(int k=i+1;k<=x;k++){
                q.push(matrix[k][y]);
            }
            for(int k=y-1;k>=j;k--){
                q.push(matrix[x][k]);
            }
            for(int k=x-1;k>i;k--){
                q.push(matrix[k][j]);
            }
            i++;
            j++;
            x--;
            y--;
        }
        if(i==x && j<=y){
            for(int k=j;k<=y;k++){
                q.push(matrix[x][k]);
            }
        }
        if(j==y && i<x){
            for(int k=i;k<=x;k++){
                q.push(matrix[k][j]);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
