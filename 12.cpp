// Find all the unique quadruple from the given array that sums up to the given number.

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l=j+1;
                int h=n-1;
                while(l<h){
                    if(arr[i]+arr[j]+arr[l]+arr[h]==k){
                        vector<int> v;
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[l]);
                        v.push_back(arr[h]);
                        ans.push_back(v);
                        l++;
                        h--;
                    }
                    else if(arr[i]+arr[j]+arr[l]+arr[h]<k){
                        l++;
                    }
                    else{
                        h--;
                    }
                }
            }
        }
        set<vector<int>> s;
        vector<vector<int>> res;
        for(int i=0;i<ans.size();i++){
            if(s.find(ans[i])==s.end()){
                res.push_back(ans[i]);
                s.insert(ans[i]);
            }
        }
        return res;
    }
};
