// Divide an array into two sets S1 and S2 such that the absolute
// difference between their sums is minimum and find the minimum difference

class Solution{

  public:
	int minDifference(int arr[], int n)  {
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    int s1=solve(arr,n,sum);
	    return sum-2*s1;
	}
	int solve(int arr[],int n,int sum){
	    bool t[n+1][sum+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=sum;j++){
	            if(i==0){
	                t[i][j]=false;
	            }
	            if(j==0){
	                t[i][j]=true;
	            }
	        }
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1]<=j){
	                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
	            }
	            else{
	                t[i][j]=t[i-1][j];
	            }
	        }
	    }
	    int res=0;
	    for(int j=0;j<=sum/2;j++){
	        if(t[n][j]==true){
	            res=j;
	        }
	    }
	    return res;
	}
};
