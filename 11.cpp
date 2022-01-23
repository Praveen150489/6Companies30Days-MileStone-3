// Generate and print all binary numbers with decimal values from 1 to N.

vector<string> generate(int N)
{
	// Your code here
	vector<string> ans;
	for(int i=1;i<=N;i++){
	    string str="";
	    int n=i;
	    while(n>0){
	        str+=(n%2 + '0');
	        n=n/2;
	    }
	    reverse(str.begin(),str.end());
	    ans.push_back(str);
	}
	return ans;
}
