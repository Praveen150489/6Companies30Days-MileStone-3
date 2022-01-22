// Stock span Problem.

class Solution
{
    public:
    //Function to calculate the span of stock’s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       int a[n];
       for(int i=0;i<n;i++){
           a[i]=price[i];
       }
       sort(a,a+n);
       vector<int> ans;
       bool flag=false;
       for(int i=0;i<n;i++){
           if(a[i]!=price[i]){
               flag=true;
               break;
           }
       }
       if(flag==false){
           for(int i=0;i<n;i++){
               ans.push_back(i+1);
           }
           return ans;
       }
       vector<int> v;
       for(int i=n-1;i>=0;i--){
           v.push_back(a[i]);
       }
       flag=false;
       for(int i=0;i<n;i++){
           if(v[i]!=price[i]){
               flag=true;
               break;
           }
       }
       if(flag==false){
           for(int i=0;i<n;i++){
               if(i==0){
                   ans.push_back(1);
               }
               else if(v[i]==v[i-1]){
                   ans.push_back(ans[ans.size()-1]+1);
               }
               else{
                   ans.push_back(1);
               }
           }
           return ans;
       }
       for(int i=0;i<n;i++){
           int count=1;
           for(int j=i-1;j>=0;j--){
               if(price[j]<=price[i]){
                   count++;
               }
               else{
                   break;
               }
           }
           ans.push_back(count);
       }
       return ans;
    }
};
