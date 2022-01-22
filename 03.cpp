// Rotate by 90 degree of square matrix in Anti-clockwise direction.

void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int n=matrix.size();
    queue<int> q;
    int i=0;
    int j=0;
    int x=n-1;
    int y=n-1;
    while(i<=x && j<=y){
        int count=0;
        for(int k=j;k<=y;k++){
            count++;
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
        count--;
        while(count>0){
            q.push(q.front());
            q.pop();
            count--;
        }
        for(int k=j;k<=y;k++){
            matrix[i][k]=q.front();
            q.pop();
        }
        for(int k=i+1;k<=x;k++){
            matrix[k][y]=q.front();
            q.pop();
        }
        for(int k=y-1;k>=j;k--){
            matrix[x][k]=q.front();
            q.pop();
        }
        for(int k=x-1;k>i;k--){
            matrix[k][j]=q.front();
            q.pop();
        }
        i++;
        j++;
        x--;
        y--;
    }

}
