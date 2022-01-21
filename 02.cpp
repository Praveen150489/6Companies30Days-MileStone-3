// Prerequisite Tasks Problem.

class Solution {
public:
    void solve(vector<int> g[],vector<bool>& vis,int start,set<int>& s,bool& flag){
        for(auto x:g[start]){
            if(s.find(x)!=s.end()){
                flag=false;
                return;
            }
            if(vis[x]==false){
                s.insert(x);
                solve(g,vis,x,s,flag);
            }
        }
        vis[start]=true;
        s.erase(start);
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> g[N];
	    for(int i=0;i<prerequisites.size();i++){
	        g[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    vector<bool> vis(N,false);
	    for(int i=0;i<N;i++){
	        if(g[i].size()==0){
	            vis[i]=true;
	        }
	    }
	    set<int> s;
	    for(int i=0;i<N;i++){
	        if(vis[i]==false){
	            bool flag=true;
	            s.insert(i);
	            solve(g,vis,i,s,flag);
	            if(flag==false){
	                return false;
	            }
	        }
	    }
	    for(int i=0;i<N;i++){
	        if(vis[i]==false){
	            return false;
	        }
	    }
	    return true;
	}
};
